/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

#include "server.h"

/* Variável global para armazenar a URL atual */
char current_url[256];

/* Função para limpar a URL removendo caracteres especiais */
static void clean_url(const char* url, char* cleaned_url, size_t max_len) {
  size_t i, j = 0;
  
  for (i = 0; url[i] != '\0' && j < max_len - 1; i++) {
    /* Remove caracteres de controle e caracteres especiais, mas permite & */
    if (isprint(url[i]) && url[i] != '<' && url[i] != '>' && 
        url[i] != '"' && url[i] != '\'' ) {
      cleaned_url[j++] = url[i];
    }
  }
  cleaned_url[j] = '\0';
}

/* Função para executar comandos bash */
char* execute_bash_command(const char* command) {
    char* output = NULL;
    FILE* fp;
    char buffer[1024];
    size_t output_size = 0;
    
    // Comandos especiais que precisam de tratamento especial
    if (strcmp(command, "help") == 0) {
        return strdup(
            "Comandos disponíveis:\n"
            "  ls, pwd, whoami, date, uptime, ps, df, du\n"
            "  cat, head, tail, grep, find, echo, wc\n"
            "  sort, uniq, cut, awk, sed, tr\n"
            "  mkdir, rmdir, touch, cp, mv, rm\n"
            "  chmod, chown, ln, tar, gzip, gunzip\n"
            "  zip, unzip, wget, curl, ping, netstat\n"
            "  ifconfig, ip, route, git, docker\n"
            "  clear - limpa o terminal\n"
            "  help - mostra esta ajuda\n"
            "\n"
            "Digite qualquer comando válido do sistema.\n"
        );
    }
    
    if (strcmp(command, "clear") == 0) {
        return strdup(""); // Retorna string vazia para limpar o terminal
    }
    
    // Comandos permitidos (whitelist para segurança)
    const char* allowed_commands[] = {
        "ls", "pwd", "whoami", "date", "uptime", "ps", "df", "du", "cat", "head", "tail",
        "grep", "find", "echo", "wc", "sort", "uniq", "cut", "awk", "sed", "tr",
        "mkdir", "rmdir", "touch", "cp", "mv", "rm", "chmod", "chown", "ln",
        "tar", "gzip", "gunzip", "zip", "unzip", "wget", "curl", "ping", "netstat",
        "ifconfig", "ip", "route", "ssh", "scp", "rsync", "git", "docker", "kubectl",
        "history", "alias", "export", "env", "set", "unset",
        "source", "which", "whereis", "type", "hash", "jobs", "bg", "fg", "kill",
        "nohup", "screen", "tmux", "vim", "nano", "less", "more", "man", "info",
        "apropos", "whatis", "locate", "updatedb", "passwd", "su", "sudo", "id",
        "groups", "who", "w", "last", "lastlog", "finger", "wall", "write", "mesg",
        "talk", "mail", "mutt", "pine", "cal", "bc", "dc", "factor", "primes",
        "seq", "shuf", "random", "uuidgen", "md5sum", "sha1sum", "sha256sum",
        "base64", "xxd", "hexdump", "od", "strings", "file", "stat", "lsof",
        "fuser", "lsof", "strace", "ltrace", "gdb", "valgrind", "perf", "top",
        "htop", "iotop", "nethogs", "iftop", "tcpdump", "wireshark", "nmap",
        "telnet", "nc", "netcat", "socat", "ssh-keygen", "ssh-copy-id",
        "ssh-add", "ssh-agent", "scp", "rsync", "sftp", "ftp", "lftp", "wget",
        "curl", "lynx", "links", "elinks", "w3m", "links2", "browsh", "termux",
        "adb", "fastboot", "dd", "fdisk", "parted", "gparted", "mkfs", "mount",
        "umount", "blkid", "lsblk", "fstab", "mtab", "proc", "sys", "dev",
        "tmp", "var", "etc", "usr", "bin", "sbin", "lib", "lib64", "home",
        "root", "boot", "opt", "mnt", "media", "srv", "sbin", "usr", "local",
        "share", "doc", "man", "info", "include", "src", "build", "dist",
        "target", "node_modules", "vendor", "composer", "npm", "yarn", "pip",
        "conda", "virtualenv", "venv", "env", "python", "python3", "node",
        "npm", "yarn", "npx", "bower", "grunt", "gulp", "webpack", "rollup",
        "parcel", "vite", "esbuild", "swc", "babel", "typescript", "tsc",
        "eslint", "prettier", "jest", "mocha", "chai", "sinon", "nyc", "istanbul",
        "coverage", "test", "spec", "e2e", "cypress", "playwright", "selenium",
        "puppeteer", "chromium", "firefox", "chrome", "safari", "edge", "opera",
        "brave", "vivaldi", "tor", "torbrowser", "chromium-browser", "google-chrome",
        "google-chrome-stable", "firefox-esr", "firefox-developer-edition",
        "thunderbird", "evolution", "kmail", "claws-mail", "mutt", "pine",
        "alpine", "mail", "sendmail", "postfix", "exim", "qmail", "dovecot",
        "cyrus", "imap", "pop3", "smtp", "http", "https", "ftp", "sftp", "scp",
        "rsync", "git", "svn", "cvs", "hg", "bzr", "darcs", "fossil", "jira",
        "confluence", "bitbucket", "github", "gitlab", "gitea", "gogs", "gitee",
        "coding", "oschina", "sourceforge", "launchpad", "codeplex", "googlecode",
        "assembla", "planio", "redmine", "trac", "bugzilla", "mantis", "fogbugz"
    };
    
    int num_allowed = sizeof(allowed_commands) / sizeof(allowed_commands[0]);
    int command_allowed = 0;
    
    // Extrai o primeiro comando (antes do primeiro espaço)
    char first_command[256];
    strncpy(first_command, command, sizeof(first_command) - 1);
    first_command[sizeof(first_command) - 1] = '\0';
    
    char* space = strchr(first_command, ' ');
    if (space) {
        *space = '\0';
    }
    
    // Verifica se o comando está na whitelist
    for (int i = 0; i < num_allowed; i++) {
        if (strcmp(first_command, allowed_commands[i]) == 0) {
            command_allowed = 1;
            break;
        }
    }
    
    if (!command_allowed) {
        return strdup("Comando não permitido por questões de segurança.\n");
    }
    
    // Executa o comando
    fp = popen(command, "r");
    if (fp == NULL) {
        return strdup("Erro ao executar comando.\n");
    }
    
    // Lê a saída do comando
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        size_t len = strlen(buffer);
        output = realloc(output, output_size + len + 1);
        if (output == NULL) {
            pclose(fp);
            return strdup("Erro de memória.\n");
        }
        strcpy(output + output_size, buffer);
        output_size += len;
    }
    
    int status = pclose(fp);
    
    if (output == NULL) {
        output = strdup("");
    }
    
    // Se o comando falhou e não há saída, adiciona uma mensagem de erro
    if (status != 0 && strlen(output) == 0) {
        char* error_msg = malloc(strlen(output) + 100);
        sprintf(error_msg, "Comando falhou com código de saída %d\n", status);
        free(output);
        return error_msg;
    }
    
    return output;
}

/* HTTP response and header for a successful request.  */

static char* ok_response =
  "HTTP/1.0 200 OK\n"
  "Content-type: text/html\n"
  "\n";

/* HTTP response for plain text */
static char* text_response =
  "HTTP/1.0 200 OK\n"
  "Content-type: text/plain\n"
  "Access-Control-Allow-Origin: *\n"
  "Access-Control-Allow-Methods: POST, GET, OPTIONS\n"
  "Access-Control-Allow-Headers: Content-Type\n"
  "\n";

/* HTTP response, header, and body indicating that the we didn't
   understand the request.  */

static char* bad_request_response = 
  "HTTP/1.0 400 Bad Request\n"
  "Content-type: text/html\n"
  "\n"
  "<html>\n"
  " <body>\n"
  "  <h1>Bad Request</h1>\n"
  "  <p>This server did not understand your request.</p>\n"
  " </body>\n"
  "</html>\n";

/* HTTP response, header, and body template indicating that the
   requested document was not found.  */

static char* not_found_response_template = 
  "HTTP/1.0 404 Not Found\n"
  "Content-type: text/html\n"
  "\n"
  "<html>\n"
  " <body>\n"
  "  <h1>Not Found</h1>\n"
  "  <p>Nao encontrada a URL %s neste servidor.</p>\n"
  " </body>\n"
  "</html>\n";

/* HTTP response, header, and body template indicating that the
   method was not understood.  */

static char* bad_method_response_template = 
  "HTTP/1.0 501 Method Not Implemented\n"
  "Content-type: text/html\n"
  "\n"
  "<html>\n"
  " <body>\n"
  "  <h1>Method Not Implemented</h1>\n"
  "  <p>The method %s is not implemented by this server.</p>\n"
  " </body>\n"
  "</html>\n";

/* Handler for SIGCHLD, to clean up child processes that have
   terminated.  */

static void clean_up_child_process (int signal_number)
{
  int status;
  wait (&status);
}

/* Process an HTTP "GET" request for PAGE, and send the results to the
   file descriptor CONNECTION_FD.  */

static void handle_get (int connection_fd, const char* page)
{
  struct server_module* module = NULL;

  /* Limpar a URL e armazenar na variável global */
  clean_url(page, current_url, sizeof(current_url));
  
  /* Mostrar a URL limpa no terminal */
  fprintf(stderr, "Cliente acessando módulo: %s\n", current_url);

  // Adicionar registro de acesso do usuário
  FILE *logf = fopen("user_access.log", "a");
  if (logf) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timebuf[32];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);

    // Tenta pegar o IP do cliente (se possível)
    // Aqui, você pode passar o IP como argumento para handle_get, se quiser detalhar mais.
    fprintf(logf, "[%s] %s\n", timebuf, current_url);
    fclose(logf);
  }

  /* Extrair apenas o caminho base antes do '?' */
  char path_only[256];
  size_t i = 0;
  while (page[i] != '\0' && page[i] != '?' && i < sizeof(path_only) - 1) {
    path_only[i] = page[i];
    i++;
  }
  path_only[i] = '\0';

  /* Se for a rota raiz "/", mostrar página de índice */
  if (strcmp(path_only, "/") == 0) {
    write(connection_fd, ok_response, strlen(ok_response));
    
    FILE* fp = fdopen(connection_fd, "w");
    if (fp != NULL) {
      fprintf(fp, "<!DOCTYPE html>\n");
      fprintf(fp, "<html lang=\"pt-BR\">\n");
      fprintf(fp, "<head>\n");
      fprintf(fp, "    <meta charset=\"UTF-8\">\n");
      fprintf(fp, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
      fprintf(fp, "    <title>Servidor de Módulos Linux</title>\n");
      fprintf(fp, "    <style>\n");
      fprintf(fp, "        body {\n");
      fprintf(fp, "            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n");
      fprintf(fp, "            margin: 0;\n");
      fprintf(fp, "            padding: 20px;\n");
      fprintf(fp, "            background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%);\n");
      fprintf(fp, "            min-height: 100vh;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .container {\n");
      fprintf(fp, "            max-width: 1200px;\n");
      fprintf(fp, "            margin: 0 auto;\n");
      fprintf(fp, "            background: white;\n");
      fprintf(fp, "            border-radius: 15px;\n");
      fprintf(fp, "            box-shadow: 0 20px 40px rgba(0,0,0,0.1);\n");
      fprintf(fp, "            overflow: hidden;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .header {\n");
      fprintf(fp, "            background: linear-gradient(45deg, #667eea, #764ba2);\n");
      fprintf(fp, "            color: white;\n");
      fprintf(fp, "            padding: 30px;\n");
      fprintf(fp, "            text-align: center;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .header h1 {\n");
      fprintf(fp, "            margin: 0;\n");
      fprintf(fp, "            font-size: 2.5em;\n");
      fprintf(fp, "            font-weight: 300;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .header p {\n");
      fprintf(fp, "            margin: 10px 0 0 0;\n");
      fprintf(fp, "            font-size: 1.2em;\n");
      fprintf(fp, "            opacity: 0.9;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .content {\n");
      fprintf(fp, "            padding: 30px;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .modules-grid {\n");
      fprintf(fp, "            display: grid;\n");
      fprintf(fp, "            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));\n");
      fprintf(fp, "            gap: 20px;\n");
      fprintf(fp, "            margin-top: 30px;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-card {\n");
      fprintf(fp, "            background: #fff;\n");
      fprintf(fp, "            border-radius: 10px;\n");
      fprintf(fp, "            padding: 20px;\n");
      fprintf(fp, "            box-shadow: 0 5px 15px rgba(0,0,0,0.1);\n");
      fprintf(fp, "            transition: transform 0.3s ease, box-shadow 0.3s ease;\n");
      fprintf(fp, "            border-left: 4px solid #667eea;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-card:hover {\n");
      fprintf(fp, "            transform: translateY(-5px);\n");
      fprintf(fp, "            box-shadow: 0 10px 25px rgba(0,0,0,0.15);\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-card h3 {\n");
      fprintf(fp, "            color: #333;\n");
      fprintf(fp, "            margin-top: 0;\n");
      fprintf(fp, "            margin-bottom: 10px;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-card p {\n");
      fprintf(fp, "            color: #666;\n");
      fprintf(fp, "            margin-bottom: 15px;\n");
      fprintf(fp, "            line-height: 1.5;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-link {\n");
      fprintf(fp, "            display: inline-block;\n");
      fprintf(fp, "            background: #667eea;\n");
      fprintf(fp, "            color: white;\n");
      fprintf(fp, "            text-decoration: none;\n");
      fprintf(fp, "            padding: 10px 20px;\n");
      fprintf(fp, "            border-radius: 5px;\n");
      fprintf(fp, "            transition: background 0.3s ease;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .module-link:hover {\n");
      fprintf(fp, "            background: #5a6fd8;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .status {\n");
      fprintf(fp, "            display: inline-block;\n");
      fprintf(fp, "            padding: 4px 8px;\n");
      fprintf(fp, "            border-radius: 3px;\n");
      fprintf(fp, "            font-size: 0.8em;\n");
      fprintf(fp, "            font-weight: bold;\n");
      fprintf(fp, "            margin-left: 10px;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .status.available {\n");
      fprintf(fp, "            background: #d4edda;\n");
      fprintf(fp, "            color: #155724;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "        .status.required {\n");
      fprintf(fp, "            background: #fff3cd;\n");
      fprintf(fp, "            color: #856404;\n");
      fprintf(fp, "        }\n");
      fprintf(fp, "    </style>\n");
      fprintf(fp, "</head>\n");
      fprintf(fp, "<body>\n");
      fprintf(fp, "    <div class=\"container\">\n");
      fprintf(fp, "        <div class=\"header\">\n");
      fprintf(fp, "            <h1>🐧 Servidor de Módulos Linux</h1>\n");
      fprintf(fp, "            <p>Sistema de gerenciamento e monitoramento do sistema operacional</p>\n");
      fprintf(fp, "        </div>\n");
      fprintf(fp, "        <div class=\"content\">\n");
      fprintf(fp, "            <h2>📋 Módulos Disponíveis</h2>\n");
      fprintf(fp, "            <div class=\"modules-grid\">\n");
      
      // Listar módulos dinamicamente
      DIR *d = opendir(".");
      struct dirent *dir;
      if (d) {
          while ((dir = readdir(d)) != NULL) {
              if (strstr(dir->d_name, ".so") && strncmp(dir->d_name, "librust", 7) != 0) {
                  // Pega o nome base do módulo (sem .so)
                  char modname[128];
                  strncpy(modname, dir->d_name, sizeof(modname));
                  char *dot = strstr(modname, ".so");
                  if (dot) *dot = 0;

                  // Ignorar arquivos que não são módulos (ex: librust_video.so, etc)
                  if (strcmp(modname, "server") == 0 || strcmp(modname, "librust_video") == 0)
                      continue;

                  // Montar título amigável (primeira letra maiúscula)
                  char title[128];
                  snprintf(title, sizeof(title), "%c%s", toupper(modname[0]), modname+1);

                  fprintf(fp,
                      "                <div class=\"module-card\">\n"
                      "                    <h3>%s</h3>\n"
                      "                    <a href=\"/%s\" class=\"module-link\">Acessar Módulo</a>\n"
                      "                </div>\n",
                      title, modname
                  );
              }
          }
          closedir(d);
          fprintf(fp, "            </div>\n");
      } else {
          fprintf(fp, "<p>Não foi possível listar os módulos.</p>");
      }
      
      fprintf(fp, "            <div style=\"margin-top: 30px; padding: 20px; background: #f8f9fa; border-radius: 10px;\">\n");
      fprintf(fp, "                <h3>ℹ️ Informações</h3>\n");
      fprintf(fp, "                <p><strong>Como usar:</strong> Clique em qualquer módulo acima para acessá-lo.</p>\n");
      fprintf(fp, "                <p><strong>Módulo de Diretórios:</strong> Use <code>/dirlist?path=/caminho/do/diretorio</code> para listar um diretório específico.</p>\n");
      fprintf(fp, "                <p><strong>Terminal:</strong> O módulo terminal permite executar comandos bash diretamente no navegador.</p>\n");
      fprintf(fp, "            </div>\n");
      fprintf(fp, "        </div>\n");
      fprintf(fp, "    </div>\n");
      fprintf(fp, "</body>\n");
      fprintf(fp, "</html>\n");
      fflush(fp);
    }
    return;
  }

  /* Make sure the requested page begins with a slash and does not
     contain any additional slashes -- we don't support any
     subdirectories.  */
  if (*path_only == '/' && strchr (path_only + 1, '/') == NULL) {
    char module_file_name[64];
    /* O nome do módulo é só o caminho base sem a barra inicial */
    snprintf (module_file_name, sizeof (module_file_name),
              "%s.so", path_only + 1);
    module = module_open (module_file_name);
  }

  if (module == NULL) {
    /* Either the requested page was malformed, or we couldn't open a
       module with the indicated name.  Either way, return the HTTP
       response 404, Not Found.  */
    char response[1024];

    /* Generate the response message.  */
    snprintf (response, sizeof (response), not_found_response_template, page);
    /* Send it to the client.  */
    write (connection_fd, response, strlen (response));
  }
  else {
    /* The requested module was loaded successfully.  */

    /* Send the HTTP response indicating success, and the HTTP header
       for an HTML page.  */
    write (connection_fd, ok_response, strlen (ok_response));
    /* Invoke the module, which will generate HTML output and send it
       to the client file descriptor.  */
    (*module->generate_function) (connection_fd);
    /* We're done with the module.  */
    module_close (module);
  }
}

/* Process an HTTP "POST" request for PAGE, and send the results to the
   file descriptor CONNECTION_FD.  */

static void handle_post (int connection_fd, const char* page, const char* post_data)
{
  /* Verifica se é uma requisição para executar comando do terminal */
  if (strcmp(page, "/terminal/execute") == 0) {
    char* command = NULL;
    char* output = NULL;
    
    /* Parse o comando do POST data */
    if (strncmp(post_data, "command=", 8) == 0) {
      command = strdup(post_data + 8);
      
      /* URL decode do comando */
      char* src = command;
      char* dst = command;
      while (*src) {
        if (*src == '%' && src[1] && src[2]) {
          char hex[3] = {src[1], src[2], 0};
          *dst++ = (char)strtol(hex, NULL, 16);
          src += 3;
        } else if (*src == '+') {
          *dst++ = ' ';
          src++;
        } else {
          *dst++ = *src++;
        }
      }
      *dst = '\0';
      
      /* Executa o comando */
      output = execute_bash_command(command);
      
      /* Envia resposta */
      write(connection_fd, text_response, strlen(text_response));
      write(connection_fd, output, strlen(output));
      
      free(command);
      free(output);
    } else {
      /* POST data inválido */
      write(connection_fd, bad_request_response, strlen(bad_request_response));
    }
  } else {
    /* Método POST não suportado para outras URLs */
    char response[1024];
    snprintf(response, sizeof(response), bad_method_response_template, "POST");
    write(connection_fd, response, strlen(response));
  }
}

/* Handle a client connection on the file descriptor CONNECTION_FD.  */

static void handle_connection (int connection_fd)
{
  char buffer[2048];
  ssize_t bytes_read;

  /* Read some data from the client.  */
  bytes_read = read (connection_fd, buffer, sizeof (buffer) - 1);
  if (bytes_read > 0) {
    char method[sizeof (buffer)];
    char url[sizeof (buffer)];
    char protocol[sizeof (buffer)];

    /* Some data was read successfully.  NUL-terminate the buffer so
       we can use string operations on it.  */
    buffer[bytes_read] = '\0';
    /* The first line the client sends is the HTTP request, which is
       composed of a method, the requested page, and the protocol
       version.  */
    
    sscanf (buffer, "%s %s %s", method, url, protocol);

    /* The client may send various header information following the
       request.  For this HTTP implementation, we don't care about it.
       However, we need to read any data the client tries to send.  Keep
       on reading data until we get to the end of the header, which is
       delimited by a blank line.  HTTP specifies CR/LF as the line
       delimiter.  */
    char* header_end = strstr (buffer, "\r\n\r\n");
    if (header_end == NULL) {
      header_end = strstr (buffer, "\n\n");
    }
    
    char* post_data = NULL;
    if (header_end != NULL) {
      post_data = header_end + (strstr(buffer, "\r\n\r\n") ? 4 : 2);
      if (strlen(post_data) == 0) {
        post_data = NULL;
      }
    }
    
    /* Make sure the last read didn't fail.  If it did, there's a
       problem with the connection, so give up.  */
    if (bytes_read == -1) {
      close (connection_fd);
      return;
    }
    /* Check the protocol field.  We understand HTTP versions 1.0 and
       1.1.  */
    if (strcmp (protocol, "HTTP/1.0") && strcmp (protocol, "HTTP/1.1")) {
      /* We don't understand this protocol.  Report a bad response.  */
      write (connection_fd, bad_request_response, 
	     sizeof (bad_request_response));
    }
    else if (strcmp (method, "GET") == 0) {
      /* A valid GET request.  Process it.  */
      handle_get (connection_fd, url);
    }
    else if (strcmp (method, "POST") == 0) {
      /* A valid POST request.  Process it.  */
      handle_post (connection_fd, url, post_data);
    }
    else {
      /* This server only implements the GET and POST methods.  The client
	 specified some other method, so report the failure.  */
      char response[1024];

      snprintf (response, sizeof (response),
		bad_method_response_template, method);
      write (connection_fd, response, strlen (response));
    }
  }
  else if (bytes_read == 0)
    /* The client closed the connection before sending any data.
       Nothing to do.  */
    ;
  else 
    /* The call to read failed.  */
    system_error ("read");
}


void server_run (struct in_addr local_address, uint16_t port)
{
  struct sockaddr_in socket_address;
  int rval;
  struct sigaction sigchld_action;
  int server_socket;

  /* Install a handler for SIGCHLD that cleans up child processes that
     have terminated.  */
  memset (&sigchld_action, 0, sizeof (sigchld_action));
  sigchld_action.sa_handler = &clean_up_child_process;
  sigaction (SIGCHLD, &sigchld_action, NULL);

  /* Create a TCP socket.  */
  server_socket = socket (PF_INET, SOCK_STREAM, 0);
  if (server_socket == -1)
    system_error ("socket");
  /* Construct a socket address structure for the local address on
     which we want to listen for connections.  */
  memset (&socket_address, 0, sizeof (socket_address));
  socket_address.sin_family = AF_INET;
  socket_address.sin_port = port;
  socket_address.sin_addr = local_address;
  /* Bind the socket to that address.  */
  rval = bind (server_socket, &socket_address, sizeof (socket_address));
  if (rval != 0)
    system_error ("bind");
  /*  Instruct the socket to accept connections.  */
  rval = listen (server_socket, 10);
  if (rval != 0)
    system_error ("listen");

  if (verbose) {
    /* In verbose mode, display the local address and port number
       we're listening on.  */
    socklen_t address_length;
    
    /* Find the socket's local address.  */
    address_length = sizeof (socket_address);
    rval = getsockname (server_socket, &socket_address, &address_length);
    assert (rval == 0);
    /* Print a message.  The port number needs to be converted from
       network byte order (big endian) to host byte order.  */
    printf ("server listening on %s:%d\n", 
	    inet_ntoa (socket_address.sin_addr), 
	    (int) ntohs (socket_address.sin_port));
  }

  /* Loop forever, handling connections.  */
  while (1) {
    struct sockaddr_in remote_address;
    socklen_t address_length;
    int connection;
    pid_t child_pid;

    /* Accept a connection.  This call blocks until a connection is
       ready.  */
    address_length = sizeof (remote_address);
    connection = accept (server_socket, &remote_address, &address_length);
    if (connection == -1) {
      /* The call to accept failed.  */
      if (errno == EINTR)
	/* The call was interrupted by a signal.  Try again.  */
	continue;
      else
	/* Something else went wrong.  */
	system_error ("accept");
    }

    /* We have a connection.  Print a message if we're running in
       verbose mode.  */
    if (verbose) {
      socklen_t address_length;

      /* Get the remote address of the connection.  */
      address_length = sizeof (socket_address);
      rval = getpeername (connection, &socket_address, &address_length);
      assert (rval == 0);
      /* Print a message.  */
      printf ("connection accepted from %s\n",
	      inet_ntoa (socket_address.sin_addr));
    }

    /* Fork a child process to handle the connection.  */
    child_pid = fork ();
    if (child_pid == 0) {
      /* This is the child process.  It shouldn't use stdin or stdout,
	 so close them.  */
      close (STDIN_FILENO);
      close (STDOUT_FILENO);
      /* Also this child process shouldn't do anything with the
	 listening socket.  */
      close (server_socket);
      /* Handle a request from the connection.  We have our own copy
	 of the connected socket descriptor.  */
      handle_connection (connection);
      /* All done; close the connection socket, and end the child
	 process.  */
      close (connection);
      exit (0);
    }
    else if (child_pid > 0) {
      /* This is the parent process.  The child process handles the
	 connection, so we don't need our copy of the connected socket
	 descriptor.  Close it.  Then continue with the loop and
	 accept another connection.  */
      close (connection);
    }
    else
      /* Call to fork failed.  */
      system_error ("fork");
  }
}
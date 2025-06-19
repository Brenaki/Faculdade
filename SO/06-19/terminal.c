/***********************************************************************
* Terminal Web Module - Permite usar terminal bash no navegador       *
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#include "server.h"

/* Template HTML para o terminal web */
static char* page_template =
  "<!DOCTYPE html>\n"
  "<html>\n"
  "<head>\n"
  "    <meta charset=\"UTF-8\">\n"
  "    <title>Terminal Web</title>\n"
  "    <style>\n"
  "        body {\n"
  "            font-family: 'Courier New', monospace;\n"
  "            background-color: #1e1e1e;\n"
  "            color: #ffffff;\n"
  "            margin: 0;\n"
  "            padding: 20px;\n"
  "        }\n"
  "        .terminal-container {\n"
  "            background-color: #000000;\n"
  "            border: 1px solid #333;\n"
  "            border-radius: 5px;\n"
  "            padding: 10px;\n"
  "            height: 500px;\n"
  "            overflow-y: auto;\n"
  "        }\n"
  "        .terminal-output {\n"
  "            white-space: pre-wrap;\n"
  "            word-wrap: break-word;\n"
  "            margin-bottom: 10px;\n"
  "        }\n"
  "        .command-line {\n"
  "            display: flex;\n"
  "            align-items: center;\n"
  "        }\n"
  "        .prompt {\n"
  "            color: #00ff00;\n"
  "            margin-right: 10px;\n"
  "        }\n"
  "        .command-input {\n"
  "            background: transparent;\n"
  "            border: none;\n"
  "            color: #ffffff;\n"
  "            font-family: 'Courier New', monospace;\n"
  "            font-size: 14px;\n"
  "            flex: 1;\n"
  "            outline: none;\n"
  "        }\n"
  "        .error {\n"
  "            color: #ff4444;\n"
  "        }\n"
  "        .success {\n"
  "            color: #44ff44;\n"
  "        }\n"
  "        .info {\n"
  "            color: #4444ff;\n"
  "        }\n"
  "    </style>\n"
  "</head>\n"
  "<body>\n"
  "    <h1>Terminal Web</h1>\n"
  "    <div class=\"terminal-container\" id=\"terminal\">\n"
  "        <div class=\"terminal-output\">\n"
  "            <span class=\"info\">Terminal Web iniciado. Digite 'help' para ver comandos disponíveis.</span>\n"
  "        </div>\n"
  "        <div class=\"command-line\">\n"
  "            <span class=\"prompt\">$</span>\n"
  "            <input type=\"text\" class=\"command-input\" id=\"commandInput\" placeholder=\"Digite um comando...\">\n"
  "        </div>\n"
  "    </div>\n"
  "\n"
  "    <script>\n"
  "        const terminal = document.getElementById('terminal');\n"
  "        const commandInput = document.getElementById('commandInput');\n"
  "        let commandHistory = [];\n"
  "        let historyIndex = -1;\n"
  "\n"
  "        function addOutput(text, className = '') {\n"
  "            const output = document.createElement('div');\n"
  "            output.className = 'terminal-output' + (className ? ' ' + className : '');\n"
  "            output.textContent = text;\n"
  "            terminal.insertBefore(output, terminal.lastElementChild);\n"
  "            terminal.scrollTop = terminal.scrollHeight;\n"
  "        }\n"
  "\n"
  "        function executeCommand(command) {\n"
  "            if (!command.trim()) return;\n"
  "\n"
  "            // Adiciona comando ao histórico\n"
  "            commandHistory.push(command);\n"
  "            historyIndex = commandHistory.length;\n"
  "\n"
  "            // Mostra o comando executado\n"
  "            addOutput('$ ' + command);\n"
  "\n"
  "            // Envia comando para o servidor\n"
  "            fetch('/terminal/execute', {\n"
  "                method: 'POST',\n"
  "                headers: {\n"
  "                    'Content-Type': 'application/x-www-form-urlencoded',\n"
  "                },\n"
  "                body: 'command=' + encodeURIComponent(command)\n"
  "            })\n"
  "            .then(response => response.text())\n"
  "            .then(output => {\n"
  "                if (output.trim()) {\n"
  "                    // Se o comando for 'clear', limpa o terminal\n"
  "                    if (command.trim() === 'clear') {\n"
  "                        // Remove todos os outputs exceto a linha de comando atual\n"
  "                        const outputs = terminal.querySelectorAll('.terminal-output');\n"
  "                        outputs.forEach(output => {\n"
  "                            if (output !== terminal.lastElementChild) {\n"
  "                                output.remove();\n"
  "                            }\n"
  "                        });\n"
  "                    } else {\n"
  "                        addOutput(output);\n"
  "                    }\n"
  "                }\n"
  "            })\n"
  "            .catch(error => {\n"
  "                addOutput('Erro ao executar comando: ' + error, 'error');\n"
  "            });\n"
  "        }\n"
  "\n"
  "        commandInput.addEventListener('keydown', function(e) {\n"
  "            if (e.key === 'Enter') {\n"
  "                const command = commandInput.value;\n"
  "                commandInput.value = '';\n"
  "                executeCommand(command);\n"
  "            } else if (e.key === 'ArrowUp') {\n"
  "                e.preventDefault();\n"
  "                if (historyIndex > 0) {\n"
  "                    historyIndex--;\n"
  "                    commandInput.value = commandHistory[historyIndex];\n"
  "                }\n"
  "            } else if (e.key === 'ArrowDown') {\n"
  "                e.preventDefault();\n"
  "                if (historyIndex < commandHistory.length - 1) {\n"
  "                    historyIndex++;\n"
  "                    commandInput.value = commandHistory[historyIndex];\n"
  "                } else {\n"
  "                    historyIndex = commandHistory.length;\n"
  "                    commandInput.value = '';\n"
  "                }\n"
  "            }\n"
  "        });\n"
  "\n"
  "        // Foca no input quando a página carrega\n"
  "        commandInput.focus();\n"
  "    </script>\n"
  "</body>\n"
  "</html>\n";

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

void module_generate(int fd) {
    FILE* fp;
    
    // Cria um stream correspondente ao descritor de arquivo do cliente
    fp = fdopen(fd, "w");
    if (fp == NULL) {
        return;
    }
    
    // Gera a saída HTML
    fprintf(fp, page_template);
    
    // Finaliza e limpa o stream
    fflush(fp);
} 
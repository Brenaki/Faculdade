/***********************************************************************
* Network Interfaces Module - Mostra interfaces de rede do sistema    *
***********************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "server.h"

/* Função para executar comando e retornar saída */
static char* execute_command(const char* command) {
    char* output = NULL;
    FILE* fp;
    char buffer[1024];
    size_t output_size = 0;
    
    fp = popen(command, "r");
    if (fp == NULL) {
        return strdup("Erro ao executar comando.\n");
    }
    
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
    
    pclose(fp);
    
    if (output == NULL) {
        output = strdup("");
    }
    
    return output;
}

void module_generate(int fd) {
    FILE* fp;
    char* ip_output;
    char* ifconfig_output;
    
    /* Criar stream correspondente ao descritor de arquivo do socket do cliente */
    fp = fdopen(fd, "w");
    assert(fp != NULL);
    
    /* Executar comandos para obter informações de rede */
    ip_output = execute_command("ip addr show 2>/dev/null || ifconfig 2>/dev/null");
    ifconfig_output = execute_command("ifconfig 2>/dev/null || ip addr show 2>/dev/null");
    
    /* Gerar HTML */
    fprintf(fp, "<!DOCTYPE html>\n");
    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "    <meta charset='UTF-8'>\n");
    fprintf(fp, "    <title>Interfaces de Rede</title>\n");
    fprintf(fp, "    <style>\n");
    fprintf(fp, "        body { font-family: Arial, sans-serif; background: #f5f5f5; margin: 0; padding: 20px; }\n");
    fprintf(fp, "        .container { max-width: 1200px; margin: 0 auto; background: white; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); padding: 20px; }\n");
    fprintf(fp, "        h1 { color: #333; text-align: center; margin-bottom: 30px; }\n");
    fprintf(fp, "        .section { margin-bottom: 30px; }\n");
    fprintf(fp, "        .section h2 { color: #555; border-bottom: 2px solid #007acc; padding-bottom: 10px; }\n");
    fprintf(fp, "        pre { background: #f8f8f8; border: 1px solid #ddd; border-radius: 4px; padding: 15px; overflow-x: auto; font-family: 'Courier New', monospace; font-size: 12px; line-height: 1.4; }\n");
    fprintf(fp, "        .refresh-btn { background: #007acc; color: white; border: none; padding: 10px 20px; border-radius: 4px; cursor: pointer; font-size: 14px; }\n");
    fprintf(fp, "        .refresh-btn:hover { background: #005a9e; }\n");
    fprintf(fp, "        .info { background: #e7f3ff; border-left: 4px solid #007acc; padding: 15px; margin-bottom: 20px; border-radius: 4px; }\n");
    fprintf(fp, "    </style>\n");
    fprintf(fp, "</head>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "    <div class='container'>\n");
    fprintf(fp, "        <h1>🌐 Interfaces de Rede</h1>\n");
    
    fprintf(fp, "        <div class='info'>\n");
    fprintf(fp, "            <strong>Informação:</strong> Esta página mostra as interfaces de rede do sistema usando comandos Linux.\n");
    fprintf(fp, "        </div>\n");
    
    fprintf(fp, "        <button class='refresh-btn' onclick='location.reload()'>🔄 Atualizar</button>\n");
    fprintf(fp, "        <br><br>\n");
    
    /* Seção com comando ip addr */
    fprintf(fp, "        <div class='section'>\n");
    fprintf(fp, "            <h2>📡 Comando: ip addr show</h2>\n");
    fprintf(fp, "            <pre>%s</pre>\n", ip_output);
    fprintf(fp, "        </div>\n");
    
    /* Seção com comando ifconfig */
    fprintf(fp, "        <div class='section'>\n");
    fprintf(fp, "            <h2>🔧 Comando: ifconfig</h2>\n");
    fprintf(fp, "            <pre>%s</pre>\n", ifconfig_output);
    fprintf(fp, "        </div>\n");
    
    /* Informações adicionais */
    fprintf(fp, "        <div class='section'>\n");
    fprintf(fp, "            <h2>📋 Comandos Úteis</h2>\n");
    fprintf(fp, "            <pre>");
    fprintf(fp, "# Ver interfaces de rede\n");
    fprintf(fp, "ip addr show\n");
    fprintf(fp, "ifconfig\n");
    fprintf(fp, "\n");
    fprintf(fp, "# Ver apenas interfaces ativas\n");
    fprintf(fp, "ip link show up\n");
    fprintf(fp, "\n");
    fprintf(fp, "# Ver estatísticas de rede\n");
    fprintf(fp, "ip -s link show\n");
    fprintf(fp, "\n");
    fprintf(fp, "# Ver rotas\n");
    fprintf(fp, "ip route show\n");
    fprintf(fp, "            </pre>\n");
    fprintf(fp, "        </div>\n");
    
    fprintf(fp, "    </div>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");
    
    /* Liberar memória */
    free(ip_output);
    free(ifconfig_output);
    
    /* Finalizar */
    fflush(fp);
} 
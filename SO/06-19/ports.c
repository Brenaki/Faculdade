#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

static char* execute_command(const char* command) {
    char* output = NULL;
    FILE* fp;
    char buffer[1024];
    size_t output_size = 0;
    fp = popen(command, "r");
    if (fp == NULL) return strdup("Erro ao executar comando.\n");
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
    if (output == NULL) output = strdup("");
    return output;
}

void module_generate(int fd) {
    FILE* fp = fdopen(fd, "w");
    assert(fp != NULL);
    char* ss_output = execute_command("ss -tuln 2>/dev/null");
    char* netstat_output = execute_command("netstat -tuln 2>/dev/null");
    fprintf(fp, "<html><head><meta charset='UTF-8'><title>Portas de Conexão</title><style>body{font-family:Arial,sans-serif;background:#f5f5f5;padding:20px;}h1{color:#333;}pre{background:#f8f8f8;border:1px solid #ddd;border-radius:4px;padding:15px;overflow-x:auto;}</style></head><body><h1>Portas de Conexão Abertas</h1><h2>ss -tuln</h2><pre>%s</pre><h2>netstat -tuln</h2><pre>%s</pre></body></html>", ss_output, netstat_output);
    free(ss_output);
    free(netstat_output);
    fflush(fp);
} 
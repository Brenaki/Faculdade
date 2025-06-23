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
    char* ip_route = execute_command("ip route show 2>/dev/null");
    char* route_n = execute_command("route -n 2>/dev/null");
    fprintf(fp, "<html><head><meta charset='UTF-8'><title>Rotas de Internet</title><style>body{font-family:Arial,sans-serif;background:#f5f5f5;padding:20px;}h1{color:#333;}pre{background:#f8f8f8;border:1px solid #ddd;border-radius:4px;padding:15px;overflow-x:auto;}</style></head><body><h1>Rotas de Internet</h1><h2>ip route show</h2><pre>%s</pre><h2>route -n</h2><pre>%s</pre></body></html>", ip_route, route_n);
    free(ip_route);
    free(route_n);
    fflush(fp);
} 
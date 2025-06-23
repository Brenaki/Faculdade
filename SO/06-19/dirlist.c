#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "server.h"

static void parse_url_params(const char* url, char* path, size_t maxlen) {
    char* query_start = strchr(url, '?');
    if (!query_start) {
        strncpy(path, "/", maxlen);
        return;
    }
    char* params = strdup(query_start + 1);
    char* token = strtok(params, "&");
    while (token) {
        char* eq = strchr(token, '=');
        if (eq) {
            *eq = '\0';
            if (strcmp(token, "path") == 0) {
                strncpy(path, eq + 1, maxlen);
                break;
            }
        }
        token = strtok(NULL, "&");
    }
    free(params);
    if (strlen(path) == 0) strncpy(path, "/", maxlen);
}

void module_generate(int fd) {
    FILE* fp = fdopen(fd, "w");
    assert(fp != NULL);
    char path[256] = "/";
    parse_url_params(current_url, path, sizeof(path));
    DIR* dir = opendir(path);
    fprintf(fp, "<html><head><meta charset='UTF-8'><title>Conteúdo do Diretório</title><style>body{font-family:Arial,sans-serif;background:#f5f5f5;padding:20px;}h1{color:#333;}table{border-collapse:collapse;width:100%;}th,td{border:1px solid #ccc;padding:8px;text-align:left;}th{background:#eee;}</style></head><body><h1>Conteúdo do Diretório: %s</h1>", path);
    if (!dir) {
        fprintf(fp, "<p>Não foi possível abrir o diretório.</p></body></html>");
        fflush(fp);
        return;
    }
    fprintf(fp, "<table><tr><th>Nome</th><th>Tipo</th></tr>");
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        const char* tipo = (entry->d_type == DT_DIR) ? "Diretório" : (entry->d_type == DT_REG) ? "Arquivo" : "Outro";
        fprintf(fp, "<tr><td>%s</td><td>%s</td></tr>", entry->d_name, tipo);
    }
    closedir(dir);
    fprintf(fp, "</table></body></html>");
    fflush(fp);
} 
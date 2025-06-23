#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "server.h"

void module_generate(int fd) {
    FILE *fp = fdopen(fd, "w");
    assert(fp != NULL);

    fprintf(fp, "<html><head><meta charset='UTF-8'><title>Histórico de Acessos</title>");
    fprintf(fp, "<style>body{font-family:Arial,sans-serif;background:#f5f5f5;padding:20px;}table{border-collapse:collapse;width:100%%;}th,td{border:1px solid #ccc;padding:8px;text-align:left;}th{background:#eee;}</style></head><body>");
    fprintf(fp, "<h1>Histórico de Acessos do Usuário</h1>");
    fprintf(fp, "<table><tr><th>Data/Hora</th><th>Módulo Acessado</th></tr>");

    FILE *logf = fopen("user_access.log", "r");
    if (logf) {
        char line[512];
        while (fgets(line, sizeof(line), logf)) {
            char *sep = strchr(line, ']');
            if (sep) {
                *sep = 0;
                char *mod = sep + 2;
                char *newline = strchr(mod, '\n');
                if (newline) *newline = 0;
                fprintf(fp, "<tr><td>%s</td><td>%s</td></tr>", line + 1, mod);
            }
        }
        fclose(logf);
    } else {
        fprintf(fp, "<tr><td colspan='2'>Nenhum acesso registrado ainda.</td></tr>");
    }

    fprintf(fp, "</table></body></html>");
    fflush(fp);
}

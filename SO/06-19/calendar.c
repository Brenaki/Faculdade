#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "server.h"

/* Função para extrair parâmetros da URL */
static void parse_url_params(const char* url, int* year, int* month, int* day) {
    char* query_start = strchr(url, '?');
    if (query_start == NULL) {
        /* Se não há parâmetros, usar data atual */
        time_t now = time(NULL);
        struct tm* tm_info = localtime(&now);
        *year = tm_info->tm_year + 1900;
        *month = tm_info->tm_mon + 1;
        *day = tm_info->tm_mday;
        return;
    }
    
    /* Inicializar com valores padrão */
    *year = 0;
    *month = 0;
    *day = 0;
    
    /* Extrair parâmetros da query string */
    char* params = strdup(query_start + 1);
    char* token = strtok(params, "&");
    
    while (token != NULL) {
        char* equal_sign = strchr(token, '=');
        if (equal_sign != NULL) {
            *equal_sign = '\0';
            char* value = equal_sign + 1;
            
            if (strcmp(token, "year") == 0) {
                *year = atoi(value);
            } else if (strcmp(token, "month") == 0) {
                *month = atoi(value);
            } else if (strcmp(token, "day") == 0) {
                *day = atoi(value);
            }
        }
        token = strtok(NULL, "&");
    }
    
    free(params);
    
    /* Se algum parâmetro não foi fornecido, usar data atual */
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    
    if (*year == 0) *year = tm_info->tm_year + 1900;
    if (*month == 0) *month = tm_info->tm_mon + 1;
    if (*day == 0) *day = tm_info->tm_mday;
}

/* Função para verificar se um ano é bissexto */
static int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Função para obter o número de dias em um mês */
static int days_in_month(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

/* Função para obter o dia da semana (0 = domingo, 1 = segunda, etc.) */
static int day_of_week(int year, int month, int day) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 12; /* Meio-dia para evitar problemas com horário de verão */
    
    time_t time = mktime(&timeinfo);
    struct tm* result = localtime(&time);
    return result->tm_wday;
}

/* Função para gerar o HTML do calendário */
static void generate_calendar_html(FILE* fp, int year, int month, int day) {
    const char* month_names[] = {
        "Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
        "Jul", "Ago", "Set", "Out", "Nov", "Dez"
    };
    const char* day_names[] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb"};
    int days_in_current_month = days_in_month(year, month);
    int first_day_of_month = day_of_week(year, month, 1);
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    int current_year = tm_info->tm_year + 1900;
    int current_month = tm_info->tm_mon + 1;
    int current_day = tm_info->tm_mday;

    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "  <title>Calendário - %s %d</title>\n", month_names[month-1], year);
    fprintf(fp, "  <meta charset='UTF-8'>\n");
    fprintf(fp, "  <style>\n");
    fprintf(fp, "    body { font-family: Arial, sans-serif; background: #f0f0f0; margin: 0; padding: 0; }\n");
    fprintf(fp, "    .cal-wrap { max-width: 350px; margin: 20px auto; background: #fff; border-radius: 8px; box-shadow: 0 2px 8px #0001; padding: 16px; }\n");
    fprintf(fp, "    .cal-head { text-align: center; margin-bottom: 8px; }\n");
    fprintf(fp, "    .cal-nav { text-align: center; margin-bottom: 8px; }\n");
    fprintf(fp, "    .cal-nav a { margin: 0 6px; text-decoration: none; color: #1976d2; font-weight: bold; }\n");
    fprintf(fp, "    table { width: 100%%; border-collapse: collapse; }\n");
    fprintf(fp, "    th, td { width: 14%%; text-align: center; padding: 4px; }\n");
    fprintf(fp, "    th { background: #e3e3e3; }\n");
    fprintf(fp, "    td.other-month { color: #bbb; }\n");
    fprintf(fp, "    td.selected { background: #1976d2; color: #fff; border-radius: 4px; }\n");
    fprintf(fp, "    td.today { background: #ffeb3b; color: #222; border-radius: 4px; font-weight: bold; }\n");
    fprintf(fp, "    .info { text-align: center; font-size: 0.95em; color: #444; margin-top: 10px; }\n");
    fprintf(fp, "  </style>\n");
    fprintf(fp, "</head>\n<body>\n");
    fprintf(fp, "<div class='cal-wrap'>\n");
    fprintf(fp, "  <div class='cal-head'><b>Calendário</b><br>%s %d</div>\n", month_names[month-1], year);
    int prev_month = month - 1, prev_year = year;
    if (prev_month == 0) { prev_month = 12; prev_year--; }
    int next_month = month + 1, next_year = year;
    if (next_month == 13) { next_month = 1; next_year++; }
    fprintf(fp, "  <div class='cal-nav'>");
    fprintf(fp, "<a href='/calendar?year=%d&month=%d&day=%d'>&lt;</a>", prev_year, prev_month, day);
    fprintf(fp, "<a href='/calendar'>Hoje</a>");
    fprintf(fp, "<a href='/calendar?year=%d&month=%d&day=%d'>&gt;</a>", next_year, next_month, day);
    fprintf(fp, "</div>\n");
    fprintf(fp, "  <table>\n    <tr>\n");
    for (int i = 0; i < 7; i++) fprintf(fp, "<th>%s</th>", day_names[i]);
    fprintf(fp, "</tr>\n");
    int current_calendar_day = 1;
    for (int week = 0; week < 6; week++) {
        fprintf(fp, "<tr>");
        for (int weekday = 0; weekday < 7; weekday++) {
            if (week == 0 && weekday < first_day_of_month) {
                int prev_month_days = days_in_month(prev_year, prev_month);
                int day_number = prev_month_days - first_day_of_month + weekday + 1;
                fprintf(fp, "<td class='other-month'>%d</td>", day_number);
            } else if (current_calendar_day > days_in_current_month) {
                int day_number = current_calendar_day - days_in_current_month;
                fprintf(fp, "<td class='other-month'>%d</td>", day_number);
                current_calendar_day++;
            } else {
                if (current_calendar_day == day) {
                    fprintf(fp, "<td class='selected'>%d</td>", current_calendar_day);
                } else if (current_calendar_day == current_day && month == current_month && year == current_year) {
                    fprintf(fp, "<td class='today'>%d</td>", current_calendar_day);
                } else {
                    fprintf(fp, "<td>%d</td>", current_calendar_day);
                }
                current_calendar_day++;
            }
        }
        fprintf(fp, "</tr>\n");
        if (current_calendar_day > days_in_current_month) break;
    }
    fprintf(fp, "  </table>\n");
    fprintf(fp, "  <div class='info'>Data: %d/%d/%d<br>URL: %s<br>%s tem %d dias%s</div>\n", day, month, year, current_url, month_names[month-1], days_in_current_month, is_leap_year(year) ? "<br>Ano bissexto!" : "");
    fprintf(fp, "</div>\n</body>\n</html>\n");
}

void module_generate (int fd)
{
    int year, month, day;
    FILE* fp;
    
    /* Extrair parâmetros da URL global */
    parse_url_params(current_url, &year, &month, &day);
    
    /* Validar parâmetros */
    if (year < 1900 || year > 2100) year = 2024;
    if (month < 1 || month > 12) month = 1;
    if (day < 1 || day > days_in_month(year, month)) day = 1;
    
    /* Criar stream correspondente ao descritor de arquivo do socket do cliente */
    fp = fdopen (fd, "w");
    assert (fp != NULL);
    
    /* Gerar o calendário completo com design moderno */
    generate_calendar_html(fp, year, month, day);
    
    /* Finalizar; liberar o stream */
    fflush (fp);
} 
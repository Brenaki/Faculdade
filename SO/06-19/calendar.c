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
        *month = 0; /* 0 indica que não foi especificado */
        *day = 0;   /* 0 indica que não foi especificado */
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
    
    /* Se o ano não foi fornecido, usar ano atual */
    if (*year == 0) {
        time_t now = time(NULL);
        struct tm* tm_info = localtime(&now);
        *year = tm_info->tm_year + 1900;
    }
    
    /* Se o mês não foi fornecido, manter como 0 (ano completo) */
    /* Se o mês foi fornecido mas o dia não, usar dia 1 */
    if (*month > 0 && *day == 0) {
        *day = 1;
    }
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

/* Função para gerar o HTML de um mês específico */
static void generate_month_html(FILE* fp, int year, int month, int selected_day) {
    const char* month_names[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    const char* day_names[] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb"};
    int days_in_current_month = days_in_month(year, month);
    int first_day_of_month = day_of_week(year, month, 1);
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    int current_year = tm_info->tm_year + 1900;
    int current_month = tm_info->tm_mon + 1;
    int current_day = tm_info->tm_mday;

    fprintf(fp, "<div class='month-calendar'>\n");
    fprintf(fp, "  <h3>%s %d</h3>\n", month_names[month-1], year);
    fprintf(fp, "  <table>\n    <tr>\n");
    for (int i = 0; i < 7; i++) fprintf(fp, "<th>%s</th>", day_names[i]);
    fprintf(fp, "</tr>\n");
    
    int current_calendar_day = 1;
    for (int week = 0; week < 6; week++) {
        fprintf(fp, "<tr>");
        for (int weekday = 0; weekday < 7; weekday++) {
            if (week == 0 && weekday < first_day_of_month) {
                int prev_month = month - 1, prev_year = year;
                if (prev_month == 0) { prev_month = 12; prev_year--; }
                int prev_month_days = days_in_month(prev_year, prev_month);
                int day_number = prev_month_days - first_day_of_month + weekday + 1;
                fprintf(fp, "<td class='other-month'>%d</td>", day_number);
            } else if (current_calendar_day > days_in_current_month) {
                int day_number = current_calendar_day - days_in_current_month;
                fprintf(fp, "<td class='other-month'>%d</td>", day_number);
                current_calendar_day++;
            } else {
                if (current_calendar_day == selected_day) {
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
    fprintf(fp, "</div>\n");
}

/* Função para gerar o HTML do calendário completo */
static void generate_calendar_html(FILE* fp, int year, int month, int day) {
    const char* month_names[] = {
        "Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
        "Jul", "Ago", "Set", "Out", "Nov", "Dez"
    };
    
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    int current_year = tm_info->tm_year + 1900;
    int current_month = tm_info->tm_mon + 1;
    int current_day = tm_info->tm_mday;

    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "  <title>Calendário - %d</title>\n", year);
    fprintf(fp, "  <meta charset='UTF-8'>\n");
    fprintf(fp, "  <style>\n");
    fprintf(fp, "    body { font-family: Arial, sans-serif; background: #f0f0f0; margin: 0; padding: 20px; }\n");
    fprintf(fp, "    .cal-wrap { max-width: 1200px; margin: 20px auto; background: #fff; border-radius: 8px; box-shadow: 0 2px 8px #0001; padding: 16px; }\n");
    fprintf(fp, "    .cal-head { text-align: center; margin-bottom: 20px; }\n");
    fprintf(fp, "    .cal-nav { text-align: center; margin-bottom: 20px; }\n");
    fprintf(fp, "    .cal-nav a { margin: 0 6px; text-decoration: none; color: #1976d2; font-weight: bold; padding: 8px 16px; border-radius: 4px; background: #e3f2fd; }\n");
    fprintf(fp, "    .cal-nav a:hover { background: #bbdefb; }\n");
    fprintf(fp, "    .months-grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); gap: 20px; }\n");
    fprintf(fp, "    .month-calendar { background: #fafafa; border-radius: 8px; padding: 15px; }\n");
    fprintf(fp, "    .month-calendar h3 { text-align: center; color: #333; margin-top: 0; }\n");
    fprintf(fp, "    table { width: 100%%; border-collapse: collapse; }\n");
    fprintf(fp, "    th, td { width: 14%%; text-align: center; padding: 4px; font-size: 12px; }\n");
    fprintf(fp, "    th { background: #e3e3e3; font-weight: bold; }\n");
    fprintf(fp, "    td.other-month { color: #bbb; }\n");
    fprintf(fp, "    td.selected { background: #1976d2; color: #fff; border-radius: 4px; }\n");
    fprintf(fp, "    td.today { background: #ffeb3b; color: #222; border-radius: 4px; font-weight: bold; }\n");
    fprintf(fp, "    .info { text-align: center; font-size: 0.95em; color: #444; margin-top: 20px; }\n");
    fprintf(fp, "    .year-selector { text-align: center; margin-bottom: 20px; }\n");
    fprintf(fp, "    .year-selector input { padding: 8px; border: 1px solid #ddd; border-radius: 4px; margin-right: 10px; }\n");
    fprintf(fp, "    .year-selector button { padding: 8px 16px; background: #1976d2; color: white; border: none; border-radius: 4px; cursor: pointer; }\n");
    fprintf(fp, "  </style>\n");
    fprintf(fp, "</head>\n<body>\n");
    fprintf(fp, "<div class='cal-wrap'>\n");
    fprintf(fp, "  <div class='cal-head'><b>Calendário</b><br>%d</div>\n", year);
    
    /* Navegação */
    fprintf(fp, "  <div class='cal-nav'>");
    fprintf(fp, "<a href='/calendar?year=%d'>&lt; %d</a>", year-1, year-1);
    fprintf(fp, "<a href='/calendar'>Hoje</a>");
    fprintf(fp, "<a href='/calendar?year=%d'>%d &gt;</a>", year+1, year+1);
    fprintf(fp, "</div>\n");
    
    /* Seletor de ano */
    fprintf(fp, "  <div class='year-selector'>\n");
    fprintf(fp, "    <form method='get' action='/calendar'>\n");
    fprintf(fp, "      <input type='number' name='year' value='%d' min='1900' max='2100' placeholder='Ano'>\n", year);
    fprintf(fp, "      <button type='submit'>Ir para Ano</button>\n");
    fprintf(fp, "    </form>\n");
    fprintf(fp, "  </div>\n");
    
    /* Se month > 0, mostrar apenas o mês específico */
    if (month > 0) {
        fprintf(fp, "  <div class='months-grid'>\n");
        generate_month_html(fp, year, month, day);
        fprintf(fp, "  </div>\n");
        
        /* Navegação entre meses */
        int prev_month = month - 1, prev_year = year;
        if (prev_month == 0) { prev_month = 12; prev_year--; }
        int next_month = month + 1, next_year = year;
        if (next_month == 13) { next_month = 1; next_year++; }
        
        fprintf(fp, "  <div class='cal-nav'>");
        fprintf(fp, "<a href='/calendar?year=%d&month=%d'>&lt; %s</a>", prev_year, prev_month, month_names[prev_month-1]);
        fprintf(fp, "<a href='/calendar?year=%d'>Ver Ano Completo</a>", year);
        fprintf(fp, "<a href='/calendar?year=%d&month=%d'>%s &gt;</a>", next_year, next_month, month_names[next_month-1]);
        fprintf(fp, "</div>\n");
    } else {
        /* Mostrar todos os meses do ano */
        fprintf(fp, "  <div class='months-grid'>\n");
        for (int m = 1; m <= 12; m++) {
            generate_month_html(fp, year, m, 0);
        }
        fprintf(fp, "  </div>\n");
    }
    
    fprintf(fp, "  <div class='info'>Ano: %d%s<br>URL: %s<br>%s</div>\n", 
            year, is_leap_year(year) ? " (Ano bissexto!)" : "", current_url, 
            month > 0 ? month_names[month-1] : "Ano completo");
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
    if (month < 0 || month > 12) month = 0; /* 0 = mostrar ano completo */
    if (day < 0 || day > 31) day = 0;
    
    /* Se month > 0, validar o mês específico */
    if (month > 0 && day > days_in_month(year, month)) {
        day = 1;
    }
    
    /* Criar stream correspondente ao descritor de arquivo do socket do cliente */
    fp = fdopen (fd, "w");
    assert (fp != NULL);
    
    /* Gerar o calendário completo com design moderno */
    generate_calendar_html(fp, year, month, day);
    
    /* Finalizar; liberar o stream */
    fflush (fp);
} 
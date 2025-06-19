//
// Programa de demonstração para cálculo de média através de processos filhos,
// e processamento no processo pai.
//
//  gcc calcula_media.c -o calcula_media -D N=1000
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <math.h>
#include <string.h>

#define MIN_PROCESSES 5
#define MAX_PROCESSES 1000

typedef struct {
    int filho;
    int pid;
    int status;      // Status de saída do processo
    int num_registros; // Quantidade de registros processados
} vet_filhos;

// Estrutura para armazenar os resultados de cada registro
typedef struct {
    int id;          // Identificação do registro (aluno)
    float media;     // Média calculada
} Resultado;

// Variável global para armazenar todos os resultados
vet_filhos *pid_filhos;

// Estrutura para armazenar as posições das linhas no arquivo
typedef struct {
    long *posicoes;
    int count;
} PosicaoLinhas;

// Função para obter as posições de todas as linhas no arquivo
PosicaoLinhas obter_posicoes_linhas(const char *filename) {
    PosicaoLinhas resultado = {NULL, 0};
    FILE *file = fopen(filename, "r");
    if (!file) {
        resultado.count = -1;
        return resultado;
    }
    
    // Primeira passagem para contar linhas
    int count = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') count++;
    }
    
    // Alocar memória para as posições
    resultado.posicoes = (long*)malloc((count + 1) * sizeof(long));
    if (!resultado.posicoes) {
        fclose(file);
        resultado.count = -1;
        return resultado;
    }
    
    // Segunda passagem para armazenar posições
    rewind(file);
    resultado.posicoes[0] = 0; // Posição inicial
    int i = 1;
    long pos = 0;
    
    while ((c = getc(file)) != EOF) {
        pos++;
        if (c == '\n' && i < count + 1) {
            resultado.posicoes[i++] = pos;
        }
    }
    
    fclose(file);
    resultado.count = count;
    return resultado;
}

// Função para calcular o número ótimo de processos
int calcular_processos(int total_registros) {
    if (total_registros <= MIN_PROCESSES) {
        return total_registros; // Usar um processo por registro se for menor que o mínimo
    }
    
    int num_proc = total_registros / 10;
    
    if (num_proc < MIN_PROCESSES) {
        return MIN_PROCESSES;
    }
    
    if (num_proc > MAX_PROCESSES) {
        // Encontrar um divisor que mantenha abaixo de MAX_PROCESSES
        int divisor = 10;
        while (total_registros / divisor > MAX_PROCESSES) {
            divisor += 10;
        }
        return divisor;
    }
    
    return num_proc;
}

// Função de comparação para ordenação por média
int comp_media(const void *aa, const void *bb) {
    const Resultado *a = aa, *b = bb;
    
    #ifdef DEBUG_QSORT
        printf( "%d %d %d - %d %d %d\n", a->filho, a->pid, a->media, b->filho, b->pid, b->media  );
    #endif

    if (a->media < b->media)
        return +1;
    else if (a->media > b->media)
        return -1;
    else
        return 0;
}

int main(void) {
    char t[10];
    // Obter posições de todas as linhas no arquivo
    PosicaoLinhas linhas = obter_posicoes_linhas("notas.lst");
    if (linhas.count <= 0 || !linhas.posicoes) {
        printf("Erro ao processar o arquivo ou arquivo vazio\n");
        return -1;
    }
    
    int total_registros = linhas.count;
    printf("Total de registros no arquivo: %d\n", total_registros);
    
    // Calcular número ótimo de processos
    int num_processos = calcular_processos(total_registros);
    printf("Número ótimo de processos: %d\n", num_processos);
    
    // Aloca memória para os processos filhos
    pid_filhos = (vet_filhos*)malloc(num_processos * sizeof(vet_filhos));
    if (!pid_filhos) {
        printf("Erro de alocação de memória\n");
        free(linhas.posicoes);
        return -1;
    }
    
    // Calcular registros por processo (aproximado)
    int registros_por_processo = (total_registros + num_processos - 1) / num_processos; // Ceiling division
    printf("Registros por processo (aprox): %d\n", registros_por_processo);
    #ifdef DEBUG
      scanf("%s", t); // Foi criado para analisar os calculos de processos da aplicação.
    #endif
    
    // Nome base para arquivos temporários
    char temp_filename[100];
    
    // Inicializar identificação dos processos
    for (int i = 0; i < num_processos; i++) {
        pid_filhos[i].filho = i + 1;
        pid_filhos[i].num_registros = 0;
    }
    
    // Criar processos filhos
    for (int i = 0; i < num_processos; i++) {
        printf("Criando filho %d\n", i + 1);
        
        // Criar nome de arquivo temporário único para este processo
        sprintf(temp_filename, "temp_resultados_%d.dat", i + 1);
        
        switch (pid_filhos[i].pid = fork()) {
            case -1:
                printf("Erro na criação do processo filho\n");
                free(linhas.posicoes);
                free(pid_filhos);
                exit(-1);
                break;
                
            case 0: {
                // Processo filho
                int inicio = i * registros_por_processo;
                int fim = (i == num_processos - 1) ? total_registros - 1 : (i + 1) * registros_por_processo - 1;
                
                // Abrir arquivo de entrada
                FILE *fd = fopen("notas.lst", "r");
                if (fd == NULL) {
                    printf("Erro na abertura do arquivo de entrada\n");
                    free(linhas.posicoes);
                    exit(-1);
                }
                
                // Abrir arquivo temporário para resultados
                FILE *temp_fd = fopen(temp_filename, "w");
                if (temp_fd == NULL) {
                    printf("Erro na criação do arquivo temporário\n");
                    fclose(fd);
                    free(linhas.posicoes);
                    exit(-1);
                }
                
                int id;
                float n1, n2, n3;
                int count = 0;
                
                #ifdef DEBUG
                    printf("\nFilho %d(%d) processando registros de %d até %d\n", 
                           i+1, getpid(), inicio + 1, fim + 1); // +1 para índice humano
                #endif
                
                // Ler apenas as linhas designadas para este processo
                for (int j = inicio; j <= fim && j < total_registros; j++) {
                    // Posicionar o file pointer no início da linha designada
                    fseek(fd, linhas.posicoes[j], SEEK_SET);
                    
                    if (fscanf(fd, "%d %f %f %f", &id, &n1, &n2, &n3) != 4) {
                        break; // Erro de leitura
                    }
                    
                    float media;
                    // Calcular média
                    if (n1 + n2 <= 14.0) {
                        media = (n1 + n2 + n3) / 3.0;
                    } else {
                        media = (n1 + n2) / 2.0;
                    }
                    
                    // Escrever resultado no arquivo temporário
                    fprintf(temp_fd, "%d %.1f\n", id, media);
                    count++;
                    
                    #ifdef DEBUG
                        printf("Filho %d(%d) processou registro %d, média: %.1f\r", 
                               i+1, getpid(), id, media);
                    #endif
                }
                
                fclose(fd);
                fclose(temp_fd);
                free(linhas.posicoes); // Liberar memória no processo filho
                
                // Retornar o número de registros processados
                exit(count);
            }
        }
    }
    
    printf("\nPai (%d) aguardando %d filhos\n", getpid(), num_processos);
    
    // Preparar para coletar todos os resultados
    Resultado *todos_resultados = NULL;
    int total_processado = 0;
    
    // Esperar pelos filhos e coletar os resultados
    for (int i = 0; i < num_processos; i++) {
        #ifdef DEBUG
            printf("Pai (%d) aguardando %d(%d)\r", 
                   getpid(), pid_filhos[i].filho, pid_filhos[i].pid);
        #endif
        
        // Aguardar término do processo filho
        waitpid(pid_filhos[i].pid, &pid_filhos[i].status, 0);
        
        // Obter número de registros processados pelo filho
        pid_filhos[i].num_registros = WEXITSTATUS(pid_filhos[i].status);
        total_processado += pid_filhos[i].num_registros;
        
        // Criar nome do arquivo temporário deste processo
        sprintf(temp_filename, "temp_resultados_%d.dat", i + 1);
        
        // Abrir arquivo temporário com resultados do filho
        FILE *temp_fd = fopen(temp_filename, "r");
        if (temp_fd == NULL) {
            printf("Erro ao abrir arquivo temporário %s\n", temp_filename);
            continue;
        }
        
        // Realocar array de resultados para incluir novos dados
        Resultado *novo_array = realloc(todos_resultados, total_processado * sizeof(Resultado));
        if (novo_array == NULL) {
            printf("Erro de alocação de memória para resultados\n");
            fclose(temp_fd);
            break;
        }
        todos_resultados = novo_array;
        
        // Ler resultados do arquivo temporário
        int base_idx = total_processado - pid_filhos[i].num_registros;
        for (int j = 0; j < pid_filhos[i].num_registros; j++) {
            if (fscanf(temp_fd, "%d %f", &todos_resultados[base_idx + j].id, 
                                        &todos_resultados[base_idx + j].media) != 2) {
                printf("Erro ao ler resultado do arquivo temporário\n");
                break;
            }
        }
        
        fclose(temp_fd);
        
        remove(temp_filename); // Remover arquivo temporário
    }
    
    printf("\nTotal de registros processados: %d\n", total_processado);
    
    // Mostrar resultados não ordenados
    printf("\nMÉDIAS:\n");
    printf("ID\tMédia\n");
    printf("------------------\n");
    for (int i = 0; i < total_processado; i++) {
        printf("%d\t%.1f\n", todos_resultados[i].id, todos_resultados[i].media);
    }

    // Ordenar resultados por média
    qsort(todos_resultados, total_processado, sizeof(Resultado), comp_media);
    
    // Mostrar resultados ordenados
    printf("\nMÉDIAS ORDENADAS:\n");
    printf("ID\tMédia\n");
    printf("------------------\n");
    for (int i = 0; i < total_processado; i++) {
        printf("%d\t%.1f\n", todos_resultados[i].id, todos_resultados[i].media);
    }
    
    // Liberar memória
    free(pid_filhos);
    free(linhas.posicoes);
    free(todos_resultados);
    
    return 0;
}
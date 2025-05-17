#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>

// Estrutura para armazenar resultados da cópia
typedef struct {
    size_t buffer_size;
    double time_taken;
    char method[20];
    long bytes_copied;
} CopyResult;

// Função para obter o tamanho do arquivo
long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Função para exibir a barra de progresso
void show_progress(long current, long total, const char* method) {
    const int bar_width = 50;
    float progress = (float)current / total;
    int filled = (int)(bar_width * progress);
    
    printf("\r%s [", method);
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) printf("=");
        else if (i == filled) printf(">");
        else printf(" ");
    }
    printf("] %.1f%% (%ld/%ld bytes)", 
           progress * 100.0, 
           current, 
           total);
    fflush(stdout);
}

// Obtém o tamanho ideal do bloco para o sistema de arquivos
size_t get_block_size(const char* path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        // No Windows, usaremos um tamanho de bloco padrão já que st_blksize não está disponível
        return 4096; // Padrão de 4KB que é comum
    }
    return 4096; // Valor padrão caso stat falhe
}

// Cópia usando fread/fwrite com buffer personalizado
void copy_using_fread(const char* src, const char* dst, size_t buffer_size, CopyResult* result) {
    FILE *fsrc, *fdst;
    void *buffer;
    clock_t start, end;
    size_t bytes_read, bytes_written;
    long total_bytes = 0;
    long file_size = get_file_size(src);
    
    buffer = malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Erro: Falha ao alocar buffer de tamanho %lu\n", (unsigned long)buffer_size);
        return;
    }
    
    fsrc = fopen(src, "rb");
    if (!fsrc) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de origem '%s': %s\n", src, strerror(errno));
        free(buffer);
        return;
    }
    
    fdst = fopen(dst, "wb");
    if (!fdst) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de destino '%s': %s\n", dst, strerror(errno));
        fclose(fsrc);
        free(buffer);
        return;
    }
    
    // Define o tamanho do buffer personalizado para ambos os arquivos
    setvbuf(fsrc, NULL, _IOFBF, buffer_size);
    setvbuf(fdst, NULL, _IOFBF, buffer_size);
    
    start = clock();
    
    while ((bytes_read = fread(buffer, 1, buffer_size, fsrc)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, fdst);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Erro: Falha na escrita: %s\n", strerror(errno));
            break;
        }
        total_bytes += bytes_written;
        
        // Atualiza a barra de progresso
        if (file_size > 0) {
            show_progress(total_bytes, file_size, "fread/fwrite");
        }
    }
    
    // Nova linha após a barra de progresso
    printf("\n");
    
    end = clock();
    
    // Armazena os resultados
    result->time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    result->bytes_copied = total_bytes;
    strncpy(result->method, "fread/fwrite", sizeof(result->method) - 1);
    result->method[sizeof(result->method) - 1] = '\0';
    
    fclose(fsrc);
    fclose(fdst);
    free(buffer);
}

// Cópia usando read/write com buffer personalizado
void copy_using_read(const char* src, const char* dst, size_t buffer_size, CopyResult* result) {
    int fsrc, fdst;
    void *buffer;
    clock_t start, end;
    ssize_t bytes_read, bytes_written;
    long total_bytes = 0;
    long file_size = get_file_size(src);
    
    buffer = malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Erro: Falha ao alocar buffer de tamanho %lu\n", (unsigned long)buffer_size);
        return;
    }
    
    fsrc = open(src, O_RDONLY);
    if (fsrc == -1) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de origem '%s': %s\n", src, strerror(errno));
        free(buffer);
        return;
    }
    
    fdst = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdst == -1) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de destino '%s': %s\n", dst, strerror(errno));
        close(fsrc);
        free(buffer);
        return;
    }
    
    start = clock();
    
    while ((bytes_read = read(fsrc, buffer, buffer_size)) > 0) {
        bytes_written = write(fdst, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Erro: Falha na escrita: %s\n", strerror(errno));
            break;
        }
        total_bytes += bytes_written;
        
        // Atualiza a barra de progresso
        if (file_size > 0) {
            show_progress(total_bytes, file_size, "read/write");
        }
    }
    
    // Nova linha após a barra de progresso
    printf("\n");
    
    end = clock();
    
    // Armazena os resultados
    result->time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    result->bytes_copied = total_bytes;
    strncpy(result->method, "read/write", sizeof(result->method) - 1);
    result->method[sizeof(result->method) - 1] = '\0';
    
    close(fsrc);
    close(fdst);
    free(buffer);
}

// Registra os resultados no arquivo de log
void log_result(CopyResult* result, const char* log_file) {
    FILE* log = fopen(log_file, "a");
    if (!log) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo de log '%s': %s\n", log_file, strerror(errno));
        return;
    }
    
    fprintf(log, "%s,%lu,%.6f,%ld\n",
            result->method,
            (unsigned long)result->buffer_size,
            result->time_taken,
            result->bytes_copied);
    
    fclose(log);
}

void print_usage(const char* program_name) {
    fprintf(stderr, "Uso: %s <arquivo_origem> <arquivo_destino>\n", program_name);
    fprintf(stderr, "Exemplo: %s entrada.txt saida.txt\n", program_name);
}

int main(int argc, char* argv[]) {
    
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }
    
    const char* src = argv[1];
    const char* dst = argv[2];
    const char* log_file = "resultados_copia.csv";
    size_t block_size = get_block_size(src);
    
    // Verificar se o arquivo de origem existe
    if (access(src, F_OK) == -1) {
        fprintf(stderr, "Erro: Arquivo de origem não existe\n");
        return 1;
    }
    
    // Obter e mostrar o tamanho do arquivo
    long file_size = get_file_size(src);
    if (file_size > 0) {
        printf("Tamanho do arquivo: %ld bytes (%.2f MB)\n", 
               file_size, (float)file_size / (1024 * 1024));
    }
    
    // Tamanhos de buffer para teste
    const size_t buffer_sizes[] = {
        512,      // 0.5 KB
        4096,     // 4 KB
        8192,     // 8 KB
        16384,    // 16 KB
        65536,    // 64 KB
        131072,   // 128 KB
        262144,   // 256 KB
        1048576   // 1 MB
    };
    
    // Cria/limpa o arquivo de log e escreve o cabeçalho
    FILE* log = fopen(log_file, "w");
    if (log) {
        fprintf(log, "Metodo,TamanhoBuffer,TempoGasto,BytesCopiados\n");
        fclose(log);
    }
    
    printf("Iniciando testes de cópia de arquivo...\n");
    printf("Arquivo de origem: %s\n", src);
    printf("Arquivo de destino: %s\n", dst);
    printf("Tamanho do bloco do sistema de arquivos: %lu bytes\n\n", (unsigned long)block_size);
    
    CopyResult result;
    
    // Testa cada tamanho de buffer com ambos os métodos
    for (size_t i = 0; i < sizeof(buffer_sizes) / sizeof(buffer_sizes[0]); i++) {
        size_t current_buffer = buffer_sizes[i];
        printf("\nTestando tamanho de buffer: %lu bytes %0.2f KB\n", (unsigned long)current_buffer, (float)(current_buffer / 1024));
        
        // Testa fread/fwrite
        result.buffer_size = current_buffer;
        copy_using_fread(src, dst, current_buffer, &result);
        printf("fread/fwrite: %.6f segundos, %ld bytes copiados\n", 
               result.time_taken, result.bytes_copied);
        log_result(&result, log_file);
        
        // Testa read/write
        result.buffer_size = current_buffer;
        copy_using_read(src, dst, current_buffer, &result);
        printf("read/write: %.6f segundos, %ld bytes copiados\n", 
               result.time_taken, result.bytes_copied);
        log_result(&result, log_file);
    }
    
    printf("\nResultados foram salvos em %s\n", log_file);
    return 0;
}

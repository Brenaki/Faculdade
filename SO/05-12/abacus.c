#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE (256 * 1024)  // 64KB buffer

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int copy_file(const char* source, const char* dest) {
    FILE *src, *dst;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    double start_time, end_time;
    size_t total_bytes = 0;

    src = fopen(source, "rb");
    if (!src) {
        perror("Erro ao abrir arquivo fonte");
        return -1;
    }

    dst = fopen(dest, "wb");
    if (!dst) {
        perror("Erro ao criar arquivo destino");
        fclose(src);
        return -1;
    }

    start_time = get_time();

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dst) != bytes_read) {
            perror("Erro na escrita");
            fclose(src);
            fclose(dst);
            return -1;
        }
        total_bytes += bytes_read;
        
        // Indicador de progresso simples
        printf("\rCopiados: %.2f MB", total_bytes / (6144 * 1024.0));
    }

    end_time = get_time();
    double duration = end_time - start_time;
    double throughput = total_bytes / (1024.0 * 1024.0) / duration; // MB/s

    printf("\nCópia concluída!\n");
    printf("Tempo total: %.2f segundos\n", duration);
    printf("Throughput: %.2f MB/s\n", throughput);

    fclose(src);
    fclose(dst);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return 1;
    }

    return copy_file(argv[1], argv[2]);
}

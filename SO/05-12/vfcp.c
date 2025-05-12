#include <stdio.h> 
#include <stdlib.h>

// void file_copy(const char* input, const char* output) {}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Use: \033[0;31m%s <input_file> <output_file>\033[0m\n", argv[0]);
        exit(1);
    }
    
    printf("input: %s output: %s", argv[1], argv[2]);

    // file_copy(argv[1], argv[2]);
    exit(0);
}

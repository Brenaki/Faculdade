#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char w[20];
} Palavra;

void arqWriteWord(){
    char *p;
    p = (char *) calloc(20, sizeof(char));
    printf("Informe uma Palavra à ser adicionada: ");
    scanf("%s", p);
    
    FILE *f;
    Palavra copy;
    f = fopen("words.bin", "ab");
    if(!f){
        printf("\nErro na abertura do arquivo!\n");
    }
    else{
       strcpy(copy.w, p);
       fwrite(&copy, sizeof(Palavra), 1, f);
       fclose(f);
    }

}

void read(){
    FILE *f;
    int p;
    Palavra copy;
    f = fopen("words.bin", "rb");
    if(!f){
        printf("\nErro na abertura do arquivo!");
    }
    else{
        while(fread(&copy, sizeof(Palavra), 1, f)){
            printf("%s\t", copy.w);
        }
        printf("\n");
        scanf("%d", &p);

        fclose(f);
    }
}

void game(){
    printf("JOGO LEGAL!");
}

int main(){
    int choose;
    do {
        system("clear");
        printf("\n****Bem-vindo ao Jogo da Forca\n***");
        printf("\n1 - Inserir novas palavras\n2 - Jogar\n3 - Sair\n\n");
        scanf("%d", &choose);
        printf("\n");
        switch(choose) {
            case 1:
                arqWriteWord();
                break;
            case 2:
                game();
                break;
            case 3:
                break;
            case 4:
                read();
            default:
                break;
        }
    } while(choose != 3);
    return 0;
}
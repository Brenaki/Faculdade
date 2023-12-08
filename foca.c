#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void xy(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1, lin-1});
}

typedef struct {
    char w[20];
} Palavra;

int count(){
    int count = 0;
    Palavra copy;
    FILE *f;
    f = fopen("words.bin", "rb");
    while (fread(&copy, sizeof(Palavra), 1, f))
    {
        count +=1;
    }
    
    return count;
}

int random(int count){
    int num;
    srand(time(NULL));
    num = rand() % count;
    return num;
}

void arqWriteWord(){
    char *p;
    p = (char *) calloc(20, sizeof(char));
    printf("Informe uma Palavra a ser adicionada: ");
    fflush(stdin);
    scanf("%s", p);
    strupr(p);
    
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

    printf("Palavra adicionada com sucesso!\n");
    system("pause");
    system("cls");
}

char *selectWord(){
    FILE *f;
    f = fopen("words.bin", "rb");
    char *word;
    word = (char *) calloc(20,sizeof(char));
    int numRandom = random(count());
    fseek(f, numRandom*5*sizeof(word), SEEK_SET);
    fread(word, 5*sizeof(word), 1, f);
    fclose(f);
    return (char *)word;
}

void read(){
    FILE *f;
    Palavra copy;
    int count = 0;
    f = fopen("words.bin", "rb");
    if(!f){
        printf("\nErro na abertura do arquivo!");
    }
    else{
        while(fread(&copy, sizeof(Palavra), 1, f)){
            printf("%s\t", copy.w);
            count +=1;
        }
    fclose(f);
    printf("\n\nQuantidades de palavras armazenadas: %d\n\n", count);
    system("pause");
    system("cls");
    }
}

void showHangman(int life){

}

void forca(){
    int i;
    for(i=84 ; i<=98 ; i++){
        xy(3, i); // Position Stick
        printf("%c", 196);
    }
    for(i=3 ; i<=4 ; i++){
        xy(i, 84); // Position String
        printf("%c", 179);
    }
    for(i=3 ; i<=25 ; i++){
        xy(i, 98); // Position Wood
        printf("%c", 179);
    }
    for(i=78 ; i<=98 ; i++){
        xy(25, i); // Floor
        printf("%c", 196);
    }
}

void game(){
    system("cls");
    forca();
    char word[20], answer[20];
    int underlines, correct = 0, exit = 0;
    showHangman(7);
    strcpy(word, selectWord());
    underlines = strlen(word);
    for(int i = 0; i < underlines; i++){
        xy(13, 13+(i*2));
        printf("_");
    }
    printf(word);
    printf("\n\n");
    printf("Informe uma letra, ou faca um palpite, ou digite 0 para sair: ");
    fflush(stdin);
    scanf("%s", answer);
    strupr(answer);
    while (correct == 0 && exit == 0){
        if (strlen(answer) == 1){
            if (strcmp(answer, "0") == 0)
            {
                exit = 1;
                break;
            }
            else{
                for(int i = 0; i < underlines; i++){
                    if(answer[0] == word[i]){
                        xy(12, 13+(i*2));
                        printf(answer);
                        correct = 1;
                    }
                }
            }
        }
    }
    
    printf("\n\n");
    system("pause");
    system("cls");
}

void menu(){
    int choose;
    system("cls");
    do {
        printf("\n**********************************\n");
        printf("    Bem-vindo ao Jogo da Forca    ");
        printf("\n1 - Inserir novas palavras\n2 - Jogar\n3 - Banco de palavras\n4 - Sair\n");
        printf("\n**********************************\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choose);
        fflush(stdin);
        printf("\n");
        switch(choose) {
            case 1:
                arqWriteWord();
                break;
            case 2:
                game();
                break;
            case 3:
                read();
                break;
            case 4:
            default:
                break;
        }
    } while(choose != 4);
}


int main(){
    menu();
    return 0;
}
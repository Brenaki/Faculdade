#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct {
    char w[20];
} Palavra;

Palavra shoot[7];

enum{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

enum{
    _BLACK=0,
    _BLUE=16,
    _GREEN=32,
    _CYAN=48,
    _RED=64,
    _MAGENTA=80,
    _BROWN=96,
    _LIGHTGRAY=112,
    _DARKGRAY=128,
    _LIGHTBLUE=144,
    _LIGHTGREEN=160,
    _LIGHTCYAN=176,
    _LIGHTRED=192,
    _LIGHTMAGENTA=208,
    _YELLOW=224,
    _WHITE=240
};

void gameOver(char palavra[]), game(), win();
void xy(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1, lin-1});
}
void textColor(int letras, int fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras+fundo);
}

void cls(){
    system("cls");
}

void pause(){
    system("pause");
}

void head(){
    int i, j;
    int lin1 = 5, col1= 78, lin2= 9, col2 = 90;

    for(i=col1 ; i<=col2 ; i++){
        xy(lin1, i);
        printf("%c", 196);
        if(i<(col1+2) || i>(col2-2)){
            xy(lin2, i);
            printf("%c", 196);
        }
    }
    for(i=lin1 ; i<=lin2 ; i++){
        xy(i, col1);
        printf("%c", 179);
        xy(i, col2);
        printf("%c", 179);
    }
    for(i=lin1+1 ; i<lin2 ; i++){
        for(j=col1+1 ; j<col2 ; j++){
            xy(i, j);
            printf(" ");
        }
    }
}

void neck(){
    xy(10, 86); //corpo lin1 = 10, col1 = 78, lin2 = 18, col2 = 90;
    printf("%c", 192);
    xy(10, 82);
    printf("%c", 217);
    xy(9, 86); //cabeca lin1 = 5, col1 = 80, lin2 = 9, col2 = 88;
    printf("%c", 218);
    xy(9, 82);
    printf("%c", 191);
}

void armL(){
    int i;
    for(i=11 ; i<=16 ; i++){
        xy(i,88);
        printf("%c", 179);
    }
    xy(11,88);
    printf("%c", 191);
}

void armR(){
    int i;
    for(i=11 ; i<=16 ; i++){
        xy(i,80);
        printf("%c", 179);
    }
    xy(11,80);
    printf("%c", 218);
}

void legL(){
    int i;
    for(i=19 ; i<=23; i++){
        xy(i,87);
        printf("%c",179);
    }
}

void legR(){
    int i;
    for(i=19 ; i<=23; i++){
        xy(i,81);
        printf("%c",179);
    }
}

void body(){
int i, j, lin1=10, col1=81, lin2=18, col2=87;

        for(i=col1 ; i<=col2 ; i++){
            if(i<(col1+4) || i>(col2-4)){
                xy(lin1, i); // Position of once bar
                printf("%c", 196);
            }
            xy(lin2, i);
            printf("%c", 196);
        }
        for(i=lin1 ; i<=lin2 ; i++){
            xy(i, col1);
            printf("%c", 179);
            xy(i, col2);
            printf("%c", 179);
        }
        for(i=lin1+1 ; i<lin2 ; i++){
            for(j=col1+1 ; j<col2 ; j++){
                xy(i, j);
                printf(" "); // space
            }
        }
}

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
    textColor(GREEN, _BLACK);
    printf("Palavra adicionada com sucesso!\n");
    textColor(WHITE, _BLACK);
    pause();
    cls();
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
    pause();
    cls();
    }
}

void showHangman(int life){
    switch (life)
    {
    case 0:
        head();
        break;
    case 1:
        neck();
        break;
    case 2:
        armL();
        break;
    case 3:
        armR();
        break;
    case 4:
        legL();
        break;
    case 5:
        legR();
        break;
    case 6:
        body();
        break;
    default:
        break;
    }
}

void box(){
int i;
    for(i=1 ; i<=28 ; i++){
        xy(4, i);
        printf("%c", 196);
        xy(12, i);
        printf("%c", 196);
    }
    for(i=4 ; i<=12 ; i++){
        xy(i, 1);
        printf("%c", 179);
        xy(i, 28);
        printf("%c", 179);
    }
    xy(4, 1);
    printf("%c", 218);
    xy(4, 28);
    printf("%c", 191);
    xy(12, 1);
    printf("%c", 192);
    xy(12, 28);
    printf("%c", 217);
    for(i= 0; i < 7; i++){
        xy(5+i, 2);
        printf("%d -", i+1);
    }
}

void hang(){
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

void clearShoot(){
    int i;
    for(i = 0; i <= 7; i++){
        strcpy(shoot[i].w, "___________________");
    }
}

int wordAgain(char  p[]){
    int i;
    for(i = 0; i <= 7; i++){
        if(strcmp(p, shoot[i].w)==0){
            return 1;
        }
    }
    return 0;
}

void hearts(int life){
    xy(3, 2);
    printf("Voce possui %d tentativas", life);
}

void game(){
    cls();
    hang();
    box();
    clearShoot();
    char word[20], answer[20], * hide;
    int underlines, correct = 0, exit = 0, life=7, w=0, winner=0, i;
    showHangman(7);
    strcpy(word, selectWord());
    underlines = strlen(word);
    hide = (char *) calloc(underlines, sizeof(char));
    for(i= 0; i < underlines; i++){
        xy(20, 13+(i*2));
        printf("_");
    }
    hearts(life);
    while (life > 0 && exit == 0 && winner != 1){
        fflush(stdin);
        correct = 0;
        xy(23, 1);
        printf("Informe uma letra, ou faca um palpite, ou digite 0 para sair:\n");
        scanf("%s", answer);
        strupr(answer);
        xy(28, 1);
        printf("                                     ");
        if(wordAgain(answer) == 1){
            printf("\a");
            xy(27, 1);
            printf("*Essa palavra/letra ja foi utilizada\n");
            correct = 1;
        }
        else{
            if (strlen(answer) == 1){
                if (answer[0] == '0')
                {
                    exit = 1;
                    break;
                }
                else{
                    int i;
                    for(i = 0; i < underlines; i++){
                        if(answer[0] == word[i]){
                            if(hide[i] == word[i]){
                                printf("\a");
                            }
                            textColor(GREEN, _BLACK);
                            xy(19, 13+(i*2));
                            printf("%c", answer[0]);
                            correct = 1;
                            hide[i] = word[i];
                            textColor(WHITE, _BLACK);
                        }
                    }
                }
                if(strcmp(hide, word) == 0){
                    winner = 1;
                }
            }
            else{
                if(strcmp(answer, word) == 0){
                    int i;
                    for(i =0; i<underlines; i++){
                        textColor(GREEN, _BLACK);
                        xy(19, 13+(i*2));
                        printf("%c", answer[i]);
                        correct = 1;
                        winner = 1;
                        textColor(WHITE, _BLACK);
                    }
                }
            }
        }

        if (correct == 0)
        {
            strcpy(shoot[life].w, answer);
            textColor(RED, _BLACK);
            xy(5+w, 6);
            printf("%s", shoot[life].w);
            w +=1;
            life -=1;
            textColor(WHITE, _BLACK);
        }
        xy(25,1);
        hearts(life);
        box();
        xy(24, 1);
        printf("                    ");
        showHangman(life);
    }
    free(hide);
    if(life == 0){
        printf("\n\n\n");
        xy(25, 1);
        gameOver(word);
    }
    if(winner == 1){
        printf("\n\n\n");
        xy(25, 1);
        win();
    }
    cls();
}

void win(){
    textColor(GREEN, _BLACK);
    int choose;
    printf("Voce venceu!\nParabens!!!\n\n");
    textColor(WHITE, _BLACK);
    pause();
    cls();
    printf("****************************");
    printf("\nO que deseja fazer:\n1 - JOGAR NOVAMENTE\n2 - IR PARA O MENU: \n");
    printf("****************************\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        game();
        break;
    case 2:
        textColor(BLUE, _BLACK);
        printf("\n\nObrigado por jogar!\n");
        textColor(WHITE, _BLACK);
        pause();
        break;
    }
}

void gameOver(char palavra[]){
    textColor(RED, _BLACK);
    int choose;
    printf("Voce foi enforcado(a)!\n");
    textColor(WHITE, _BLACK);
    printf("A palavra era %s\n", palavra);
    pause();
    cls();
    printf("****************************");
    printf("\nO que deseja fazer:\n1 - JOGAR NOVAMENTE\n2 - IR PARA O MENU: \n");
    printf("****************************\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        game();
        break;
    case 2:
        textColor(BLUE, _BLACK);
        printf("\n\nObrigado por jogar!\n");
        textColor(WHITE, _BLACK);
        pause();
        break;
    }
}

void menu(){
    int choose;
    cls();
    do {
        printf("**********************************\n");
        printf("    Bem-vindo ao Jogo da Forca    ");
        printf("\n1 - Inserir novas palavras\n2 - Jogar\n3 - Banco de palavras\n4 - Sair\n");
        printf("**********************************\n");
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
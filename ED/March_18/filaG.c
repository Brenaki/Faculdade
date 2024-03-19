// EXERCÍCIO DA LISTA 2
// CÓDIGO FEITO POR: Gabriel do Espírito Santo RA: 23001726
//
//


#include <stdio.h>
#include <locale.h>

#define tam 4

// variáveis globais

int fila[tam], inicio = 0, fim = 0, cont = 0 ;


void inserir(int num){
    if(cont == tam){
        printf("\n\nFILA CHEIA!\n\n");
        return;
    }


    fila[fim] = num;
    if(fim == tam ){
        fim = 0;
    }
    else{
    fim +=1 ;
    printf("elemento %d inserido\n",num);
    cont += 1;
    }
}

int filaVazia(){
    int res;
    if(cont == 0){
        res = 1;
        printf("\n\nFILA VAZIA\n\n");
    }
    else{
        res = 0;
    }

    return res;
}

void remover(){

    if(filaVazia()){
        printf("NÃO FOI POSSIVEL RETIRAR O ELEMENTO\n");
        return;
    }
    cont -=1 ;
    printf("VALOR %d RETIRADO COM SUCESSO!\n",fila[inicio]);
    inicio += 1;
    if(inicio == tam){
        inicio = 0;
    }


}

void verFila(){
    int i;

    if(!filaVazia()){
        printf("\ninicio = %d\nfim = %d\n\n",inicio,fim);

        for(i=inicio;i<fim;i++){
            printf("%d ",fila[i]);
        }
        printf("\n\n");
    }
    else{
        printf("NÃO FOI POSSÍVEL VER A FILA\n\n");
    }

}



int main(){
    setlocale(LC_ALL,"");
    inserir(10);
    inserir(40);
    inserir(30);
    inserir(20);
    verFila();
    remover();
    remover();
    remover();
    remover();
    verFila();
    return 0;
}

/* 	Nome dos Integrantes da dupla:
*	João Pedro Borsato de Ramos
*	Victor Angelo Legat Cerqueira
*/
#include <stdio.h>
#define TAM 3

int fila[TAM], inicio=0,fim=0,cont=0;

//mostra o elemento no comeco da fila, se estiver vazia imprime erro.
void Minicio(){
    if(cont==0){
        printf("pilha vazia\n");
        return;
    }
    printf("\n----------------------------\n");
    printf("inicio: %d \n",fila[inicio]);
    printf("\n----------------------------\n");
}

//insere um elemento no fim da fila, caso esteja cheia imprime erro.
void insere(int valor){
    if(cont==TAM){
        printf("fila cheia\n");
        return;
    }
    cont++;
    fila[fim]=valor;
    if(fim==TAM-1){
        fim=0;
    }
    else fim++;
    printf("elemento inserido\n");
}

//remove um elemento da fila, caso esteja vazia imprime erro.
void remov(){
    int valor;
    if(cont==0){
        printf("fila vazia\n");
        return;
    }
    valor=fila[inicio];
    cont--;
    inicio++;
    if(inicio==TAM-1){
        inicio=0;
    }
    printf("elemento removido\n");
}

//imprime os valores da fila
void imprime(){
    int x=inicio,y=0;
    printf("\n----------------------------\n");
    if(cont==0){
        printf("fila vazia\n");
        return;
    }
    while(y!=cont){
        printf("%d ",fila[x]);
        if(x==TAM-1){
            x=0;
        }
        x++;
        y++;
    }
    printf("\n----------------------------\n");
}

//fincao principal
int main(){
    remov();
    insere(10);
    insere(8);
    imprime();
    insere(12);
    insere(14);
    imprime();
    remov();
    imprime();
    insere(14);
    imprime();
    Minicio();
    insere(16);
}

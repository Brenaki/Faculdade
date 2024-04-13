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
        printf("fila vazia\n");
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
    fila[fim]=valor;
    if(fim==TAM){
        fim=0;
    }
    else fim++;
    cont++;
}

int filaVazia(){
    if(cont == 0){
	printf("\nFila vazia.\n\n");
	return 1;
    }
    return 0;
}

//remove um elemento da fila, caso esteja vazia imprime erro.
void remov(){
    int valor;
    if(filaVazia() == 1) return;
    
    cont--;
    inicio++;
    if(inicio==TAM){
        inicio=0;
    }
}

//imprime os valores da fila
void imprime(){
    int x=inicio, y=0;
    printf("\n----------------------------\n");
    if(filaVazia()==1){
        return;
    }
    while(y!=cont){
	printf("%d ", fila[x]);
	if(x==TAM){
	   x=0;
	}
	x++;
	y++;
    }
    printf("\n----------------------------\n");
}

//fincao principal
int main(){
    // 1
    remov();
    
    // 2i
    insere(10);
    insere(8);
    imprime();
    
    // 3
    insere(12);
    insere(14);
    
    // 4
    imprime();
    
    // 5
    remov();
    imprime();
    
    // 6
    insere(14); 
    imprime();
    
    // 7
    Minicio();
    
    // 8
    insere(16);
}

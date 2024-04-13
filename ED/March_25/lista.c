#include <stdio.h>
#define TAM 10

int lista[TAM];
int count = 0;

void insere(int valor){
	int i;
	if(count == TAM){
		printf("\nLista cheia\n");
		return;
	}
	for(i = count ; i>0 && valor<lista[i-1]; i--){
		lista[i] = lista[i-1];
	}
	lista[i] = valor;
	count++;
	printf("\nElemento inserido\n");
	return;
}

void insereLista(int pos, int valor){
	int i;
	if(count == TAM){
		printf("\nLista cheia\n");
		return;
	}
	if(pos<0 || pos>count){
		printf("\nPosição inválida\n");
		return;
	}
	for(i=count; i>pos; i--){
		lista[i] = lista[i-1];
	}
	lista[i] = valor;
	count++;
	printf("\nElemento inserido\n");
	return;
}

void imprimir(){
	int i;
	printf("\nLista ordenada: ");
	for(i = 0; i < count; i++){
		printf("%d ", lista[i]);
	}
}

int main(){
	insere(4);
	imprimir();
	insere(2);
	imprimir();
	insere(1);
	imprimir();
	insere(1);
	imprimir();
	insereLista(2, 3);
	imprimir();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
};

struct no *final = NULL;
struct no *inicio = NULL;

void insere(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox=NULL;
	if(inicio==NULL){
		inicio=aux;
		final=aux;
		printf("\nElemento inserido!\n");
		return;
	}
	final->prox=aux;
	final=aux;
	printf("\nElemento inserido!\n");
	return;

}

int remov(){
	int aux;
	struct no *p;
	p = (struct no*)malloc(sizeof(struct no));
	if(inicio==NULL){
		printf("\nFila vazia!\n");
		return -1;
	}
	aux=inicio->valor;
	p=inicio;
	inicio=inicio->prox;
	if(inicio==NULL){
		final==NULL;
	}
	free(p);
	printf("\nElemento removido!\n");
	return aux;
}

void inicioFila(){
	if(inicio==NULL){
		printf("\nFila vazia!\n");
	}
	printf("\nInicio da fila: %d\n", inicio->valor);
	return;
}

void imprime(){
	if(inicio==NULL){
		printf("\nFila vazia!\n");
		return;
	}
	struct no *aux;
	printf("\nFila: ");
	for(aux=inicio;aux!=NULL;aux=aux->prox){
		printf("%d ", aux->valor);
	}
	printf("\n");
}

int main(){
	insere(4);
	insere(6);
	insere(8);
	insere(10);
	imprime();
	remov();
	inicioFila();
	imprime();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
	struct no *ant;
};

struct no *final = NULL;
struct no *inicio = NULL;

void insere(int valor, int lado){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox=NULL;
	if(lado == 0){
		if(inicio==NULL){
			inicio=aux;
			final=aux;
			printf("\nElemento inserido!\n");
			return;
		}
		aux->prox=inicio;
		inicio=aux;
		printf("\nElemento inserido!\n");
		return;
	}
	if(lado==1){
		if(final==NULL){
			final=aux;
			inicio=aux;
			printf("\nElemento inserido!\n");
			return;
		}
		aux->ant = final;
		final->prox=aux;
		final=aux;
		printf("\nElemento inserido!\n");
		return;
	}
	else printf("Lado inválido!");
	return;

}

int remov(int lado){
	int aux;
	struct no *p;
	p = (struct no*)malloc(sizeof(struct no));
	if(inicio==NULL){
		printf("\nFila vazia!\n");
		return -1;
	}
	if(lado == 0){
		aux=inicio->valor;
		p=inicio;
		inicio=inicio->prox;
		if(inicio==NULL){
			final = NULL;
		}
		free(p);
		printf("\nElemento removido!\n");
		return aux;
	}
	if(lado == 1){
		aux=final->valor;
		p=final;
		final=final->ant;
		if(inicio==NULL){
			final = NULL;
		}
		free(p);
		printf("\nElemento removido!\n");
		return aux;
	}
	else printf("Lado inválido");
}

void inicioFila(){
	if(inicio==NULL){
		printf("\nFila vazia!\n");
		return;
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
	insere(4,1);
	insere(6,0);
	insere(8,1);
	insere(10,0);
	imprime();
	inicioFila();
	remov(0);
	remov(1);
	imprime();
	return 0;
}

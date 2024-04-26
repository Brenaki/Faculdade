#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
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
		struct no *ant = NULL;
		p = inicio;
		while(p->prox != NULL){
			ant = p;
			p = p->prox;
			if(ant!=NULL){
				ant->prox = NULL;
				final = ant;
			}
			else{
				inicio = NULL;
				final = NULL;
			}
		}
		aux=p->valor;
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
	imprime();
	remov(1);
	imprime();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct no {
	int dado;
	struct no *prox;
};

struct no *pilha = NULL;

void push(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->dado = valor;
	aux->prox = pilha;
	pilha = aux;
	printf("\nValor inserido\n");
}

int pop(){
	if(pilha == NULL){
		printf("\nPilha vazia\n");
		return 0;
	}
	int num;
	struct no *aux;
	aux = pilha;
	num = aux->dado;
	pilha = pilha->prox;
	printf("\nValor removido\n");
	free(aux);
	return num;
}

int main(){
	push(13);
	pop();
	push(30);
	push(21);
	push(21);
	push(18);
	pop();
	pop();
	return 0;
}

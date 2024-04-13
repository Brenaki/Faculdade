#include <stdio.h>
#include <stdlib.h>

struct no {
	int dado;
	struct no *prox;
};

struct no *pilha = NULL;

void push(int i){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->dado = i;
	aux->prox = pilha;
	pilha = aux;
	printf("\nValor inserido!\n");
}	

int pop(){
	if(pilha == NULL){
		printf("\nPilha está vazia.\n");
		return 0;
	}
	struct no *aux;
	aux = pilha;
	pilha = pilha->prox;
	printf("\nValor removido!\n");
	return aux->dado;
}

int main(){
	push(3);
	push(4);
	push(5);
	pop();
	pop();

	return 0;
}

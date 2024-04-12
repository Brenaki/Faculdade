#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
};

struct no *pilha = NULL;

int vazia(){
	if(pilha == NULL){
		return 1;
	}
	return 0;
}

void push(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox = pilha;
	pilha = aux;
	printf("\nValor inserido!\n");
}

int pop(){
	if(vazia() == 1){
		printf("\nPilha vazia!\n");
		return -1;
	}
	int num;
	struct no *aux;
	aux = pilha;
	num = aux->valor;
	pilha = aux->prox;
	free(aux);
	printf("\nValor removido!\n");
	return num;
	
}

void topoPilha(){
	if(vazia() == 1){
		printf("\nPilha vazia!\n");
		return;
	}
	printf("\nTopo da pilha: %d\n", pilha->valor);
}

void imprime(){
	struct no *aux;
	printf("\nPilha:\n");
	for(aux=pilha;aux!=NULL;aux=aux->prox){
		printf("\t[%d]\n", aux->valor);
	}
	printf("\n");

}

int main(){
	push(2);
	push(3);
	imprime();
	push(4);
	push(5);
	pop();
	topoPilha();
	imprime();
	return 0;
}

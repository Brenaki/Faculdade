/*
* Nome dos Integrantes da dupla:
* João Pedro Borsato de Ramos
* Victor Angelo Legat Cerqueira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
	char valor;
	struct no *prox;
};

struct no *pilha = NULL;

void push(char valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox = pilha;
	pilha = aux;
	printf("\nValor inserido!\n");
}

int pop(){
	if(pilha == NULL){
		printf("\nPilha vazia!\n");
		return -1;
	}
	struct no *aux;
	aux = pilha;
	pilha = aux->prox;
	free(aux);
	printf("\nValor removido!\n");
	return 0;
}

void imprime(){
	struct no *aux;
	printf("\nPilha:\n");
	for(aux=pilha;aux!=NULL;aux=aux->prox){
		printf("\t[%c]\n", aux->valor);
	}
	printf("\n");

}

int main(){
	char *p = (char *) calloc(20, sizeof(char));
	printf("Digite uma palavra: ");
	scanf("%s", p);
	
	for(int i=0;i<strlen(p);i++){
		push(p[i]);
	}
	
	imprime();
	pop();		
	printf("\nPalavra: %c\n", pilha->valor);
	imprime();
	
	return 0;
}

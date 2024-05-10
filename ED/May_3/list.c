/*
 * Nome dos Integrantes da dupla:
 * João Pedro Borsato de Ramos
 * Victor Angelo Legat Cerqueira
*/
#include <stdio.h>
#include <stdlib.h>

struct no{
	int valor;
	struct no *prox;
	struct no *ant;
};

struct no *inicio = NULL;
struct no *fim = NULL;

void insereLista(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	struct no *atual, *anterior;
	atual = inicio; anterior = NULL;
	while(atual!=NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	if(anterior==NULL){
		aux->prox = inicio;
		inicio=aux;
	}
	else{
		aux->prox = anterior->prox;
		anterior->prox=aux;
	}
	printf("\nElemento inserido!\n");

}

void recuperaLista(int valor){
        int achou = 0;
        if(inicio==NULL){
            printf("\nLista vazia!\n");
            return;
        }
        struct no *aux;
        int i=0;
        for(aux=inicio;aux!=NULL&&aux->valor<=valor;aux=aux->prox){
            if(aux->valor==valor){
                printf("\nNa %d posição está o número %d\n", i,aux->valor);
                achou=1;
            }
            i++;
        }
        if(achou == 0) printf("\nNão existe esse valor\n");
	return;
}

void removeValor(int valor, int posicao) {
    if (inicio == NULL) {
        printf("\nLista vazia! Nenhum elemento para remover.\n");
        return;
    }

    if(posicao = 0){
	struct no *anterior = NULL;
    	struct no *atual = inicio;
	while()
    }
    if(posicao = 1){
	struct no *anterior = NULL;
	struct no *atual = fim;
    }
    else printf("Posição de inválida!");

    printf("\nElemento não encontrado!\n");
}

void removeLista(int posicao) {
    if (inicio == NULL) {
        printf("\nLista vazia! Nenhum elemento para remover.\n");
        return;
    }

    if (posicao <= 0) {
        printf("\nPosição inválida. Insira um valor positivo maior que zero.\n");
        return;
    }

    struct no *anterior = NULL;
    struct no *atual = inicio;
    int i = 1;

    while (atual != NULL) {
        if (i == posicao) {
            if (atual == inicio) {
                inicio = inicio->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\nElemento na posição %d removido!\n", posicao);
            return;
        }
        anterior = atual;
        atual = atual->prox;
        i++;
    }

    printf("Posição não encontrada!\n");
}

void imprime(){
	if(inicio==NULL){
		printf("\nLista vazia!\n");
	}
	struct no *aux;
	printf("\nLista: ");
	for(aux=inicio;aux!=NULL;){
		printf("%d ", aux->valor);
		aux=aux->prox;
	}
	printf("\n");
	fflush(stdin);
}

int main(){
	printf("Ponteiro: %p", inicio);
    	insereLista(3);
	insereLista(4);
	recuperaLista(3);
	insereLista(2);
	insereLista(5);
	imprime();
	removeValor(3);
	imprime();
	removeLista(1);
	imprime();
	return 0;
}


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
};

struct no *lista = NULL;

void insereLista(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	struct no *atual = lista, *anterior = NULL;
	while(atual!=NULL && atual->valor < valor){
		anterior = atual;
		atual = atual->prox;
	}
	if(anterior==NULL){
		aux->prox = lista;
		lista=aux;
	}
	else{
		aux->prox = anterior->prox;
		anterior->prox=aux;
	}
	printf("\nElemento inserido!\n");

}

void recuperaLista(int posicao){
        int achou = 0;
	if(lista==NULL){
            printf("\nLista vazia!\n");
            return;
        }
        struct no *aux;
        aux=lista;
        for(int i=1;i<=posicao;i++){
            if(i==posicao){
                printf("\nNa %d posição está o número %d\n", posicao,aux->valor);
                return;
		achou = 1;
            }
            aux=aux->prox;
        }
	if(achou == 0) printf("\nPosição inválida\n");
        printf("\n");
	return;
}

void removeValor(int valor){
	if(lista==NULL){
            printf("\nLista vazia!\n");
            return;
        }
	int achou = 0;
	struct no *aux=NULL, *anterior=NULL, *atual;
	for(atual=lista;atual!=NULL&&atual->valor<valor;atual->prox){
		anterior = atual;
		atual = atual->prox;
		if(atual->valor == valor){
			aux=atual;
			anterior->prox = aux->prox;
			free(aux);
			printf("\nElemento removido!\n");
			achou = 1;
		}
	}
	if(achou == 0){
		printf("\nElemento não encontrado!\n");
	}
	return;
}

 void removeLista(int posicao){
        struct no *atual=lista, *anterior=NULL;
        if(lista==NULL){
            printf("\nLista vazia!\n");
            return;
        }
        if(posicao<0){
            printf("Posição inválida**");
        }
        for(int i=1;i<posicao;i++){
            if(atual->prox==NULL){
                printf("Posição inválida!");
            }
            atual=atual->prox;
            anterior=atual;
        }
        
        printf("\nElemento removido!\n");
        return;
    }

void imprime(){
	if(lista==NULL){
		printf("\nLista vazia!\n");
	}
	struct no *aux;
	printf("\nLista: ");
	for(aux=lista;aux!=NULL;aux=aux->prox){
		printf("%d ", aux->valor);
	}
	printf("\n");
}

int main(){
	insereLista(3);
	insereLista(4);
	insereLista(2);
	insereLista(5);
	imprime();
	recuperaLista(1);
	removeValor(3);
	imprime();
	removeValor(4);
	imprime();
	insereLista(3);
	imprime();
	insereLista(4);
	imprime();
	return 0;
}

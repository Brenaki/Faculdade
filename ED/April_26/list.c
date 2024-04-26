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
	struct no *atual = NULL, *anterior;
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
                printf("\nNa %d posição está o número %d ", posicao,aux->valor);
                return;
		achou = 1;
            }
            aux=aux->prox;
        }
	if(achou == 0) printf("\nPosição inválida\n");
        printf("\n");
}

void removeValor(int valor){
	int achou = 0;
	if(lista==NULL){
            printf("\nLista vazia!\n");
            return;
        }
	struct no *aux, *anterior, *atual;
	for(atual=lista;atual!=NULL;atual->prox){
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
	if(achou = 0){
		printf("\nElemento não encontrado!\n");
	}

}

 void removelista(int posicao){
        struct no *atual=lista
        struct no *anterior=NULL;
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
        return aux;
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
	imprime();
	recuperaLista(1);
	return 0;
}

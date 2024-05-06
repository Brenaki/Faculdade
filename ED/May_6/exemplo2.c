#include <stdio.h>
#include <stdlib.h>

struct no{
	int valor;
	struct no *esq;
	struct no *dir;
};

struct no *raiz = NULL;

void inserir(int valor){
	struct no *aux, *aux2;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->esq = NULL;
	aux->dir = NULL;
	if(raiz==NULL){
		raiz = aux;
		return;
	}
	else {
		while(1){
			if(aux->valor<aux2->valor){
				if(aux2->esq==NULL){
					aux2->esq = aux;
					return;
				}
				else {
					aux2 = aux2->esq;
				}
			}
			else {
				if(aux2->dir==NULL){
					aux2->dir = aux;
					return;
				}
				else 	{
					aux2 = aux2->dir;
				}
			}
		}
	}
}

void printInorder() {
    if (raiz == NULL) return;

    // primeiro recurso no lado esquerdo
    printInorder(raiz->esq);

    // então imprima os dados do nó
    printf("%d ", raiz->valor);  

    // agora recurso no lado direito
    printInorder(raiz->dir);
}

int main(){
	inserir(10);
	inserir(4);
	printInorder();
	return 0;
}

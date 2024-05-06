#include <stdio.h>
#include <stdlib.h>

struct no{
	int valor;
	struct no *esq;
	struct no *dir;
};

struct no *raiz = NULL;

void inserir(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	
	aux->valor = valor;
	aux->esq = NULL;
	aux->dir = NULL;


	if(raiz==NULL){
		raiz = aux;
		return;
	}

	else {
		struct no *atual = raiz;
		struct no *prt = NULL;
		while(1){
			prt = atual;
			if(valor < prt->valor){
				atual = atual->esq;

				if(atual == NULL){
					prt->esq = aux;
					return;
				}
			}
			else {
				atual = atual->dir;

				if(atual == NULL){
					prt->dir = aux;
					return;
				}
			}
		}
	}
}

void printInorder(struct no *aux) {
    if(aux){
			printInorder(aux->esq);
			printf("%d ", aux->valor);
			printInorder(aux->dir);
  }
}

// void printPreorder(struct no *aux) {
//     if(aux){
// 			printf("%d ", aux->valor);
// 			printInorder(aux->esq);
// 			printInorder(aux->dir);
//   }
// }

int main(){
	inserir(10);
	inserir(4);
	inserir(12);
	inserir(3);
	inserir(8);
	inserir(7);
	inserir(2);
	inserir(1);
	inserir(20);
	inserir(13);
	printf("Inorder: ");
	printInorder(raiz);
	// printf("\nPreorder: ");
	// printPreorder(raiz);
	return 0;
}

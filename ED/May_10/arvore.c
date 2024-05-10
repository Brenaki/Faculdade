#include <stdio.h>
#include <stdlib.h>

struct no{
	int valor;
	struct no *esq;
	struct no *dir;
};

struct no *raiz = NULL;

int vazia(){
	if(raiz==NULL){
		return 1;
	}
	return 0;
}

void inserir(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	
	aux->valor = valor;
	aux->esq = NULL;
	aux->dir = NULL;


	if(vazia()){
		raiz = aux;
		return;
	}

	else {
		struct no *atual = raiz;
		struct no *prt = NULL;
		while(1){
			prt = atual;
			if(valor == prt->valor){
				printf("\nNúmero não pode ser repetido!!\n");
				return;
			}
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

void buscaB(int valor){
	if(vazia()) return;

	else {
		struct no *atual = raiz;
		struct no *prt = NULL;
		while(1){
			prt = atual;
			if(valor < prt->valor){
				atual = atual->esq;

				if(atual == NULL){
					printf("\nValor não encontrado!\n");
					return;
				}
				if(atual->valor == valor){
					printf("\nValor encontrado\n");
					return;
				}
			}
			else {
				atual = atual->dir;

				if(atual == NULL){
					printf("\nValor não encontrado!\n");
					return;
				}
				if(atual->valor == valor){
					printf("\nValor encontrado!\n");
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

int main(){
	if(vazia()) printf("\nÁrvore está vazia!\n");
	inserir(10);
	inserir(10);
	inserir(4);
	inserir(12);
	inserir(3);
	inserir(8);
	inserir(8);
	inserir(7);
	inserir(2);
	inserir(1);
	inserir(20);
	inserir(13);
	printf("\nInorder: ");
	printInorder(raiz);
	printf("\n");
	inserir(13);
	buscaB(13);
	buscaB(1);
	buscaB(21);
	return 0;
}

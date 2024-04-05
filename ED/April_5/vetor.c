#include <stdio.h>
#define TAM 5

int lista[TAM];
int cont = 0;

void insereLista(int valor){
	int i;
	if(cont == TAM){
		printf("\nLista cheia\n");
		return;
	}
	for(i=cont;i>0&&valor<lista[i-1];i--){
		lista[i] = lista[i-1];
	}
	lista[i] = valor;
	cont++;
	printf("\nElemento inserido\n");
	return;
}

void recuperaLista(int posicao){
	if(posicao>=cont){
		printf("\nPosição inválida\n");
		return;
	}
	printf("\nPOSIÇÃO %d: %d\n", posicao, lista[posicao]);
	return;
}

void removeValor(int valor){
	int i, j, achou = 0;
	if(cont == 0){
		printf("\nLista Vazia\n");
		return;
	}
	for(int i=0;i<cont&&valor>=lista[i];i++){
		if(valor == lista[i]){
			for(j=i;j<cont-1;j++){
				lista[j] = lista[j+1];
			}
			cont--;
			printf("\nElemento removido\n");
			achou = 1;
		}
	}
	if(achou == 0){
		printf("\nElemento não encontrado\n");
		return;
	}
}

void removeLista(int posicao){
	int i;
	if(posicao >= cont){
		printf("\nPosição invalida\n");
		return;
	}

	for(i=posicao;i<=cont;i++){
		lista[i] = lista[i+1];
	}
	cont--;
	printf("\nElemento removido\n");
	return;
}

void imprime(){
	if(cont == 0){
		printf("\nLista Vazia\n");
		return;
	}

	int i;
	printf("\nLISTA: ");
	for(i=0;i<cont;i++){
		printf("%d ", lista[i]);
	}
	printf("\n\n");
}

int main(){
	int i;
	// Funcionado
	printf("\n\n**Todas as funções funcionado**\n\n");
	insereLista(5);
	imprime();
	insereLista(3);
	imprime();
	insereLista(7);
	imprime();
	recuperaLista(2);
	removeLista(1);
	imprime();
	removeValor(7);
	imprime();
	removeValor(3);
	
	printf("\n\n**Itens iguais**\n\n");
	// Itens Iguais
	insereLista(5);
	imprime();
	insereLista(5);
	imprime();
	insereLista(5);
	imprime();
	insereLista(3);
	imprime();
	removeValor(5);
	removeValor(3);
	removeValor(5);


	printf("\n\n**Testes de Erros**\n\n");
	// Testes Erros
	imprime();
	removeLista(3);
	removeValor(4);
	for(i=1;i<7;i++){
		insereLista(i*2);
		imprime();
	}
	recuperaLista(7);
	return 0;
}

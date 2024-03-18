#include <stdio.h>
#define TAM 5

int fila[TAM];
int start = 0, end = 0;
int count = 0;

void insert(int value){
	if(count == TAM){
		printf("\nFila cheio");
		return;
	}
	count++;
	fila[end] = value;
	if(end == TAM-1){
		end == 0;
		return;
	}
	end++;
	printf("\nElemento inserido");
/*	
*	Ideia Vini
*
*	fila[end] = value;
*	end++;
*	if(end == TAM){
*		end = 0;
*	} 
* */
}

int remover(){
	int value;
	if(count == 0){
		printf("\nFila vazia");
		return -1;
	}
	count--;
	value = fila[start];
	if(start == TAM-1){
		start = 0;
		return -1;
	}
	start++;
	printf("\nElemento removido");
	return value;
}

int startFila(){
	printf("\n%d", fila[start]);
	return start;
}

int main(){
	insert(3);
	insert(7);
	insert(14);
	startFila();
	remover();
	startFila();
	return 0;
}

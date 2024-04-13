#include <stdio.h>
#define TAM 5

int pilha[TAM], top = 0;

void push(int dado){
	if(top == TAM){
		printf("Não a espaço suficiente na pilha");
		return;
	}
	pilha[top] = dado;
	top++;
}

int pop(){
	int valor;
	if(top == 0){
		printf("Pilha está vazia");
		return -1;
	}
	valor = pilha[top-1];
	top--;
	return valor;
}

void printv(){
	for(int i = 0; i<top; i++){
		printf("%d\n", pilha[i]);
	}
}

int main(){
	push(5);
	push(7);
	push(17);
	printv();
	pop();
	printv();
	pop();
	printv();
	return 0;
}

/* 	Nome dos Integrantes da dupla:
*	João Pedro Borsato de Ramos
*	Victor Angelo Legat Cerqueira
*/

#include <stdio.h>
#define TAM 5

char expre[100];
int pilha[TAM], top = -1;

//verifica se a pilha esta vazia
int vazia(){
	if(top == -1){
		return 0;
	}
	return 1;
}

//adiciona o item para pilha e se ja estiver cheia ele imprime o erro. 
void push(int dado){
	if(top == TAM){
		printf("\nNão a espaço suficiente na pilha\n");
		return;
	}
	top++;
	pilha[top] = dado;
}

//ele diminue item para pilha e se ja estiver vazia ele imprime o erro.
int pop(){
	int valor;
	if(vazia() == 0){
		printf("\nPilha está vazia\n");
		return -1;
	}
	valor = pilha[top];
	top--;
	return valor;
}

//imprime os valores de cada item da pilha, se nao estiver nada ele imprime o erro.
void imprime(){
	if(vazia() == 0){
		return;
	}
	printf("\n****Pilha****\n");
	for(int i = top; i>=0; i--){
		printf("|%d|\n", pilha[i]);
	}
	printf("\n");
}

//imprime o valor do topo da pilha, se nao estiver nada ele imprime o erro.
void topoPilha(){
	if(vazia() == 0){
		printf("Pilha está vazia");
		return;
	}
	printf("Topo da pilha: %d", pilha[top]);
}

// verifica se expressão está com as chaves corretos, se estiver imprime que está correto, caso contrario imprime que você não fechou todas as chaves
void verificaChaves(){
	int i;
	for(i=0; expre[i]!='\0';i++){
		if(expre[i] == '{'){
			push(1);
		}
		if(expre[i] == '}'){
			pop();
		}
	}
	
	if(vazia() == 0){
		printf("\nAs chaves estão corretos.");
		return;
	}
	printf("\nAlguma(s) chaves estão errados.");
	return;
}

// verifica se expressão está com os cochetes corretos, se estiver imprime que está correto, caso contrario imprime que você não fechou todos os cochetes
void verificaCochetes(){
	int i;
	for(i=0; expre[i]!='\0';i++){
		if(expre[i] == '['){
			push(1);
		}
		if(expre[i] == ']'){
			pop();
		}
	}
	
	if(vazia() == 0){
		printf("\nOs cochetes estão corretos.");
	  verificaChaves();
		return;
	}
	printf("\nAlgum(ns) cochetes estão errados.");
	pop();
	verificaChaves();
	return;
}

// verifica se expressão está com os parenteses corretos, se estiver imprime que está correto, caso contrario imprime que você não fechou todos os parenteses
void verificaParentese(int ex){
	int i;
	for(i=0; expre[i]!='\0';i++){
		if(expre[i] == '('){
			push(1);
		}
		if(expre[i] == ')'){
			pop();
		} 
	}
	if(ex == 2){
		if(vazia() == 0){
			printf("\nOs parenteses estão corretos.");
			return;
		}
		printf("\nAlgum(ns) parenteses estão errados.");
	}
	else{
		if(vazia() == 0){
			printf("\nOs parenteses estão corretos.");
			verificaCochetes();
			return;
		}
		printf("\nAlgum(ns) parenteses estão errados.");
		pop();
		verificaCochetes();
		return;
	}
}

int main(){
	// Exercício 1 é executado
	printf("\nExercício 1\n");
	push(5);
	push(7);
	push(17);
	push(10);
	push(13);
	imprime();
	pop();
	topoPilha();
	pop();
	imprime();
	
	// Zera a pilha
	top = -1;
	
	// Exercício 2 é executado
	printf("\n\nExercício 2:\n");
	printf("Digite uma expressão: ");
	scanf("%s", expre);
	verificaParentese(2);
	
	// Zera a pilha
	top = -1;
	
	// Exercício 3 é executado
	printf("\n\nExercício 3:\n");
	printf("Digite uma expressão: ");
	scanf("%s", expre);
	verificaParentese(3);
	return 0;
}

# Pilhas

## Introdução

- Uma das estruturas de dados mais simples é a pilha.
- É, inclusive, implementada diretamente pelo hardware da maioria das máquinas modernas.

## Operações básicas de pilha

- Existem duas operações básicas que devem ser implementadas nima estrutura de pilha;
- A operação para empilhar;
- A operção para desempilhar;
- push() e pop();

## Aplicação de pilha na computação;

1. Navegação na Web;
2. Mecanismo Desfazer/Refazer;
3. Expressões Matrmáticas;
4. Compiladores;
5. Gerenciamento de memória;

## Método push

```c
#include <stdio.h>
#include <conio.h>
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
```

Código ensinado na aula é o [pilha.c](./pilha.c) onde foi escrito no quadro as funções push e pop para ter um melhor entendimento sobre essa estrutura.

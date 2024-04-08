# Pilha alocada

## push()

- Criar uma estrutura aux
- Alocar espaço para ela
- Inserir o valor nela
- Fazer aux apontar para a pilha
- Copiar a estrutura na pilha

```c
void push(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->dado = valor;
	aux->prox = pilha;
	pilha = aux;
	printf("Valor inserido");
}
```

## pop()

- Verificar se a pilha está vazia
- Criar uma estrutura aux
- Aloca espaço para aux
- Fazer aux receber a pilha
- Fazer pilha apontar para proxima da pilha
- Retorna o último valor inserido

```c
int pop(){
	if(pilha == NULL){
		printf("Pilha vazia");
		return 0;
	}
	struct *aux;
	aux = pilha;
	pilha = pilha->prox;
	printf("Valor removido");
	return aux->dado;
}
```

[Código da pilha com alocação dinâmica](.pilha.c)

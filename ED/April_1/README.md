# Alocação dinâmica

## Introdução

- Até agora só usamos alocação estática;
- Mais se precisarmos de mais espaço para ser utilizado?

## Dinâmicamente

- Nesse caso a variável é iniciada pelo compilador
- Uma variável numérica tem o valor iniciado com zero
- Já o ponteiro é inicializado com um endereço de memória inválido, ou seja, ele não aponta para lugar algum
- Não é possível obter o valor de `*ptr`, o programa vai encerrar com erro
- Só podemos ver o endereço apontado por ptr

- Nós, até agora usamos os ponteiros para guardar endereços de memória de outras variáveis
- Vamos adicionar mais um comando em nosso código
- `ptr = (int *) malloc(sizeof(int))`

## Exemplo

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr;
	printf("\nEndereço: %p\n", ptr);
	ptr = (int *) malloc(sizeof(int));
	printf("\nValor: %d\tEndereço: %p\n", *ptr, ptr);

	return 0;
}
```

### Resultado

![Resultado do código C acima](./ED0.png)

### Explicações

- O compilador buscou um bloco de memória disponível e passou esse endereço para ptr
- Mas nesse caso esse bloco já possuía valor

### Adicionando valor

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr;
	printf("\nEndereço: %p\n", ptr);
	ptr = (int *) malloc(sizeof(int));
	*ptr = 13;
	printf("\nValor: %d\tEndereço: %p\n", *ptr, ptr);

	return 0;
}
```

### Limpando memória

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr;
	printf("\nEndereço: %p\n", ptr);
	ptr = (int *) malloc(sizeof(int));
	*ptr = 13;
	printf("\nValor: %d\tEndereço: %p\n", *ptr, ptr);
	free(ptr);	

	return 0;
}
```

## Vetores com alocação dinâmica

[Exemplo com Vetor](./array.c)

# Pilha Dinâmica

[Pilha dinâmica](./pilha.c)


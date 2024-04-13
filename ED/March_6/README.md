# Revisão 2

## Struct

### Introdução

- Nem sempre conseguimos representar a realidade com os tipos de dados fornecidos pela linguagem de programação;
- Precisamos criar estruturas que comporte nossa necessidades;
- Chamamos isso de variáveis compostas **heterogêneas**.

> Nos anos 80 era comum você ter que criar variaveis para cadastrar usuario em uma locadoura, e não se conseguia criar um vetores.
```c
char nome[50];
int idade;
int id;
char sexo;
```

> Com isso foi desenvolvido as **STRUCTS**, e são utilizadas para o desenvolvedor criar seus proprios tipos.

### Definição

- Os registros podem ser compostos de outros tipos de dados definidos pelo programador.

#### Struct em C

- Sintaxe
```c
struct name_struct {
	type name;
	type name;
};
```

- Usando
```c
struct name_struct nome;
```

#### Outra Sintaxe

- Sintaxe
```c
typedef struct {
	type name;
	type name;
} struct_name;
```

- Usando
```c
name_struct nome;
```


##### Exemplo

```c
struct cliente {
	char nome[50];
	int idade;
	int Id;
	char sexo;
};
```
**OU**

```c
typedef struct {
	char nome[50];
	int idade;
	int Id;
	char sexo;
} Cliente;
```

### Como acessar os campos da variável que criamos?

- Basta usar o nome da variável seguida de um ponto.

```c
jose.idade = 35;
```

## Ponteiros estáticos

- Variáveis ponteiro são as que podem armazenar endereços de memória;
- Como registramos oportunamente, variáveis são localizações da memória que possuem:
	- Um nome pelo qual são referenciadas;
	- Um conteúdo;
	- Um endereço determinado na memória.

- Para se obter este endereço onde se localiza uma variável, utiliza-se o operador de endereço &.

### Experimente

```c
#include <stdio.h>

int main(){
	int contador = 1;
	printf("Valor = %d\n", contador);
	printf("Endereco = %x", &contador);
}
```


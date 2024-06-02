# Prova Ferrasa - 2

#### Tópicos a serem abordados

- Vetores e Matrizes
- Funções e Procedimentos
- Ponteiro

## Vetores e Matrizes

- É verdade que os termos "vetores" e "matrizes" aparecem tanto na matemática quanto na programação, mas seus papéis são um pouco diferentes em cada contexto. Enquanto na matemática eles são ferramentas para cálculos, na programação eles funcionam como estruturas de dados que nos ajudam a organizar e acessar informações de forma eficiente. Pense neles como "caixas" que armazenam dados de forma organizada.

### Vetores (Arrays)

- Imagine um vetor como uma lista de compras organizada. Cada item na sua lista ocupa uma posição específica, certo? No mundo da programação, um **vetor (ou array)** funciona da mesma forma: é uma estrutura linear que armazena uma sequência de elementos do **mesmo tipo** em posições consecutivas de memória.

- **Exemplos do cotidiano:**
  - **Lista de compras:** Cada item é um elemento do vetor (ex: "Leite", "Ovos", "Pão").
  - **Fila do banco:** Cada pessoa na fila ocupa uma posição.
  - **Letras de uma palavra:** "CASA" pode ser vista como um vetor de caracteres, onde cada letra ('C', 'A', 'S', 'A') ocupa uma posição.

- **E as Strings?**
  - Então uma String é um vetor de caracteres. A frase "Olá, mundo!" é armazenada como um vetor onde cada caractere ('O', 'l', 'á', ',', ' ', 'm', 'u', 'n', 'd', 'o', '!') ocupa uma posição.

#### Um exemplo em código C

- [Arquivo em C](./vetor.c)

```c
#include <stdio.h>

int main() {
  // Declara um vetor de inteiros com 5 posições
  int numeros[5];

  // Atribui valores a cada posição do vetor
  numeros[0] = 10;
  numeros[1] = 20;
  numeros[2] = 30;
  numeros[3] = 40;
  numeros[4] = 50;

  // Imprime os valores armazenados no vetor
  printf("Valores armazenados no vetor:\n");
  for (int i = 0; i < 5; i++) {
    printf("numeros[%d] = %d\n", i, numeros[i]);
  }

  return 0;
}
```

- Neste exemplo:

 1. Criamos um vetor chamado `numeros` que pode guardar 5 números inteiros.
 2. Atribuímos valores a cada posição do vetor (de 0 a 4).
 3. Usamos um loop `for` para percorrer o vetor e mostrar o valor de cada posição na tela.

> **Lembre-se:** Em Linguagem C, a primeira posição de um vetor sempre tem o índice 0!

## Matrizes (Arrays 2D)

- Já vimos que vetores são como listas organizadas que guardam elementos do mesmo tipo. Mas e se precisarmos de uma estrutura mais robusta, como uma tabela com linhas **e** colunas? É aí que entram as **matrizes**.

- Pense em uma matriz como um **conjunto organizado de vetores**, ou uma **"tabela" de dados**. Cada elemento em uma matriz é acessado por **dois índices**: um para a linha e outro para a coluna.

#### Analogias do dia a dia

- **Lugares no cinema:** Imagine as fileiras como linhas e as cadeiras em cada fileira como colunas. Cada lugar pode ser identificado por sua fileira e número da cadeira (ex: Fileira 3, Cadeira 5).
- **Tabela de Excel:** Cada célula em uma planilha do Excel é definida por sua linha e coluna (ex: A1, B5, C10).
- **Imagem Digital:** Uma imagem é basicamente uma matriz de pixels, onde cada pixel tem sua cor definida por sua posição na linha e coluna da imagem.

#### Matrizes em C

- Em C, declaramos uma matriz especificando o tipo de dado, o nome da matriz e o número de linhas e colunas entre colchetes:

```
tipo_de_dado nome_da_matriz[numero_de_linhas][numero_de_colunas];
```

- **Por exemplo:**

```c
int matriz[3][2]; 
```

- Isso cria uma matriz chamada matriz que pode armazenar números inteiros `int`. Ela possui **3 linhas** e **2 colunas**, totalizando 6 células.

#### Acessando elementos da Matriz

- Para acessar um elemento específico, usamos a seguinte sintaxe:

```
nome_da_matriz[indice_linha][indice_coluna]
```

#### Exemplo prático em C

- [Arquivo em C](./matriz.c)

```c
#include <stdio.h>

int main() {
  // Declara uma matriz 2x3 (2 linhas, 3 colunas)
  int matriz[2][3];

  // Preenchendo a matriz 
  matriz[0][0] = 1;
  matriz[0][1] = 2;
  matriz[0][2] = 3;
  matriz[1][0] = 4;
  matriz[1][1] = 5;
  matriz[1][2] = 6;

  // Exibindo os elementos da matriz
  printf("Valores armazenados na matriz:\n");
  for (int linha = 0; linha < 2; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      printf("%d ", matriz[linha][coluna]);
    }
    printf("\n");
  }

  return 0;
}
```

- Esse código acima imprimirá:

```
Valores armazenados na matriz:
1 2 3 
4 5 6 
```

## Funções e Procedimentos

- Imagine que você está preparando um bolo. Ao invés de misturar todos os ingredientes de uma vez, você segue uma receita com **passos bem definidos**: misturar os secos, bater as claras em neve, adicionar o leite aos poucos, e por aí vai.

- Em programação, **funções e procedimentos** são como essas etapas da receita. Eles nos permitem dividir um programa grande em **blocos menores e reutilizáveis**, tornando nosso código mais organizado, legível e fácil de manter.

### Funções (Retorna dados)

- Pense em uma função como uma máquina que **recebe ingredientes (dados)**, processa-os e **devolve um bolo pronto (resultado)**.
  - **Exemplo da Vida Real:** Uma máquina de café expresso. Você coloca água e café *(dados de entrada)*, a máquina os processa e te devolve um café pronto *(resultado)*.

#### Em Código C

- [Arquivo em C](./funcao.c)

```c
#include <stdio.h>

// Função para calcular a soma de dois números
int soma(int a, int b) {
  int resultado = a + b;
  return resultado; // Retorna o valor da soma
}

int main() {
  int num1 = 5, num2 = 3;
  int resultado_soma;

  resultado_soma = soma(num1, num2); // Chama a função 'soma'

  printf("A soma de %d e %d é %d\n", num1, num2, resultado_soma);

  return 0;
}
```

> Neste exemplo, a função `soma` recebe dois números inteiros (`a` e `b`), calcula a soma e **retorna** o resultado.

### Procedimentos (Não retorna dados)

- Procedimentos são como **instruções passo-a-passo** que **realizam uma tarefa específica**, sem necessariamente retornar um valor.
  - **Exemplo do Dia a Dia:**  A receita para "assar o bolo". Ela te guia pelos passos, mas não te entrega um bolo magicamente no final - o resultado é a ação de assar em si.

#### **Em Código C:**

- [Arquivo em C](./procedimento.c)

```c
#include <stdio.h>

// Procedimento para exibir uma mensagem de saudação
void saudacao(char nome[]) {
  printf("Olá, %s! Bem-vindo!\n", nome);
}

int main() {
  char nome_usuario[20]
  printf("Digite seu nome: ");
  scanf("%s", nome_usuario);
  saudacao(nome_usuario); // Chama o procedimento 'saudacao'

  return 0;
}
```

> No código acima, o procedimento `saudacao` recebe um nome e exibe uma mensagem.  Note que não há `return` dentro da função, pois o objetivo é apenas executar as instruções de imprimir a mensagem.

### Vantagens de usar Funções e Procedimentos

- **Organização:**  Divida seu código em partes menores e mais gerenciáveis.
- **Reutilização:**  Use a mesma função/procedimento várias vezes em diferentes partes do código.
- **Legibilidade:**  Torne seu código mais fácil de entender e depurar.
- **Abstração:**  Esconda detalhes complexos dentro de funções/procedimentos, tornando o código principal mais limpo.

## Ponteiro

- Imagine que você precisa enviar uma mensagem para um amigo que se mudou para uma nova casa, mas você não sabe o endereço exato. No entanto, você possui o endereço de uma caixa postal que seu amigo usa. Você pode colocar a mensagem na caixa postal e, como ela está **apontada** para o endereço real do seu amigo, ele receberá a mensagem sem problemas.

- Em C, **ponteiros** funcionam de maneira semelhante a essa caixa postal! Eles são variáveis especiais que **armazenam endereços de memória** onde outras variáveis residem. Em outras palavras, um ponteiro não guarda o valor em si, mas sim a **"localização"** desse valor na memória do computador.

### Analogia

- **Variável:** Pense na casa do seu amigo, onde a informação (mensagem) é armazenada diretamente.
- **Ponteiro:** A caixa postal, que guarda o endereço da casa (endereço de memória da variável) e indica onde a informação se encontra.

### Declarando Ponteiros

- Para declarar um ponteiro, utilizamos o asterisco `*` antes do nome da variável:

```c
tipo_de_dado *nome_do_ponteiro;
```

- Por exemplo:

```c
int *ptr; 
```

> Isso declara um ponteiro chamado `ptr` que pode armazenar o endereço de uma variável do tipo inteiro (`int`).

### Operadores de Ponteiros

- **Operador "Endereço-de" (&):**  Obtém o endereço de memória de uma variável.

  ```c
  int numero = 10;
  int *ptr = &numero;  // 'ptr' agora guarda o endereço de 'numero'
  ```

- **Operador "Conteúdo-de" (*):**  Acessa o valor armazenado no endereço apontado pelo ponteiro (desreferenciação).

  ```c
  printf("%d\n", *ptr); // Imprime o valor 10 (conteúdo de 'numero')
  ```

### Vantagens de usar Ponteiros

- **Manipulação Dinâmica de Memória:** Alocar e liberar memória durante a execução do programa.
- **Passagem de Parâmetros por Referência:** Modificar variáveis diretamente dentro de funções.
- **Trabalhar com Estruturas de Dados Complexas:**  Criar listas ligadas, árvores e outras estruturas.

### Exemplos Práticos

- [Arquivo em C - 1](./ponteiro1.c)

```c
#include <stdio.h>

int main() {
  int num = 5;
  int *ptr = &num; // 'ptr' aponta para 'num'

  printf("Valor de 'num': %d\n", num);
  printf("Endereço de 'num': %p\n", &num);
  printf("Valor de 'ptr': %p\n", ptr); // Mostra o endereço armazenado
  printf("Conteúdo apontado por 'ptr': %d\n", *ptr);

  return 0;
}
```

- [Arquivo em C - 2](./ponteiro1.c)

```c
#include <stdio.h>

void troca(int *a, int *b){
 int c = *a;
 *a = *b;
 *b = c;
}

int main() {
  int a = 13, b = 6;
  printf("Elementos antes da troca:\nA:%d\tB:%d", a, b);
  troca(&a, &b);
  printf("Elementos depois da troca:\nA:%d\tB:%d", a, b);

  return 0;
}
```

# Exercícios

## Exercício 8.1

- **Considerando os itens a seguir**:

- (1) Registrador $v0
- (2) syscall
- (3) Registrador $a0
- (4) Coprocessador 0
- (5) Kernel
- (6) Serviço print_string
- (7) Serviço read_int

- **preencha** as lacunas abaixo, conforme o item mais adequado:

- (5) Núcleo do sistema operacional, responsável por gerenciar os dispositivos de entrada e saída, como mouse, teclado e tela
- (1) Por meio deste registrador, é possível passar um argumento para chamada de sistema
- (3) Parte principal do suporte em hardware para controle de execeções
- (4) Instrução MIPS
- (6) Selecionado por meio da atribuição do valor igual a 4 no registrador $v0
- (7) Selecionado por meio da atribuição do valor igual a 5 em $v0 e devolve o resultado da chamada por meio do mesmo registrador $v0
- (1) O número da função/serviço do sistema operacional é especificado por meio deste registrador

## Exercício 8.2

- **Crie um programa que imprima a mensagem "Hello World!" em tela**.

- [Código em Assembly](./ex82.asm)

## Exercício 8.3

- **Crie um programa que imprima um valor inteiro em tela**.

- [Código em Assembly](./ex83.asm/)

## Exercício 8.4

- **Crie um programa que leia um valor inteiro do teclado, salve esse valor em uma variável em memória e imprima o valor em tela**. *Dica: Use a configuração de janela pop-up no MARS para chamadas de sistema de entrada de valores*.

- [Código em Assembly](./ex84.asm)

## Exercício 8.5

- **Crie um programa que some os elementos de um vetor e imprima o valor da soma em tela**.

- [Código em Assembly](./ex85.asm)

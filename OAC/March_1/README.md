# Aula prática - 01

## Exercícios

- [x] 4.1
- [x] [4.2](./ex4.2.asm "Subtração de variaveis")
- [x] [4.3](./ex4.3.asm "Fazer indices impares receberem valores de uma variavel")
- [x] [4.4](./ex4.4.asm "Qual é o resultado de uma variavel?")
- [x] [4.5](./ex4.5.asm "Codígo Assembly com perguntas a serem respondidas")

### Exercício 4.1 - Relacione os termos seguir

- (1) 1w
- (2) deslocamento (offset)
- (3) registrador de referência (ponteiro) para acesso à memória em loads ou stores
- (4) little endian
- (5) imediato
- (6) la(load addrees)
- (7) addi $t0, $t1, 32
- (8) armazenamento de 1 Bytes em memória
- (9) .data
- (10) .text

- **preencha** as lacunas abaixo, conforme o termo acima mais adequado:

- (4) formato de representação de words em memória
- (6) pseudo-instrução
- (7) exemplo de instrução que usa um operando imediato
- (1) load word
- (8) `sb $t0, 3($s2)`
- (10) Informa ao montador o inicio da seção de código do programa
- (2) O valor na instrução `lw $t0, 4($s0)`
- (9) Informa ao montador o inicio da seção de dados
- (3) O registrador `$s1` na instrução `sw $t5, 0($s1)`
- (5) Valor codificado na instrução de máquina como operando

### Exercício 4.2 - Preencha o programa a seguir

- De forma que ao término da execução do programa, a variavel `z` tenha como resultado a subtração de x por y.

[Código da aplicação](./ex4.2.asm)

### Exercício 4.3 - Considerando o fragmento de programa a seguir

- Complete o programa de forma que as posições ímpares do vetor `v` recebam o valor de alfa. Não empregue laços(estrutura de repetição).

[Código da aplicação](./ex4.3.asm)

### Exercício 4.4 - Responda

- Qual será o resultado armazenado em $t0? Use o MARS para verificar se sua resposta está correta.

> $t0 = 2

[Código da aplicação](./ex4.4.asm)

### Exercício 4.5 - Considere o segmento de dados de um programa a seguir

Responda:

- Quantos Bytes são ocupados pelo segmento de dados?
- Quantos Bytes são desperdiçados (não usados pelo programa) pela restrição de alinhamento?
- É possível modificar o programa de forma a não perder espaço em memória devido ao alinhamento?

> Dica: *Você pode montar um programa (Assembly) mesmo qye ele não tenha o segmento de código (text).*

1. 52 bytes
2. 6 bytes
3. Sim, declarando inicialmente todas as .words e após os .bytes

[Código da aplicação](./ex4.5.asm)

# Introdução Análise de Algoritmo

- Nas última aulas de Estrutura de Dados começamos de forma implicita a análisar algoritmos contando o tempo.
- Fatores que podem fazer alterar o tempo são:
  - Hardwares diferentes;
  - A memória estar limpa ou não;
  - O sistema operacional;
  - A versão do sitema operacional;
  - Entre outros.

- Com muitas variáveis para calcular a qualidade do algoritmo, foi desenvolvidos métodos analiticos para fazer os calculos de eficiência do algoritmo.
- Pensando nisso foi desenvolvido um número `t` de operações primitivas que um algoritmo realiza.

- Operações Primitivas:
  - Comparar objetos;
  - Retorno de métodos;
  - Atribuições de variáveis;
  - Entre outras operações simples.

## Exemplo de algoritmo


```
maxVetor(A, n){
  // ENTRADA: arranjo A com n >= 0 elementos
  // SAIDA: max, o maior elemento em A
  max = A[0]; // chute inicial
  para(i=0;i<n;i++) faça {
    se A[i]>max então
      max = A[i];
  }
retorne (max)
}
```

### Analise:

#### Pior dos casos:


```
2
1 + n + 2(n-1)
2(n-1)
2(n-1)
1
----------------
2 + 1 + n + 2n - 2 + 2n - 2 + 2n - 2 + 1
1 + 3 + 7n - 6
4 + 7n - 6
7n - 2 
```
#### Melhor dos casos:


```
2
1 + n + 2(n-1)
2(n-1)
1
----------------
2 + 1 + n + 2n - 2 + 2n - 2 + n
4 + 5n - 4
5n
```

## Analise Assintótica

- Concentra-se na taxa de crescimento do tempo de execução como uma função do tamanho da entrada n, obtendo-se um quadro geral do comportamento.

- Notação O (BIG O)
  - Definição: Sejam f(n) e g(n) funções mapeando inteiros não negativos em números reais.
  - Dizemos que f(n) é O(g(n)) se existe uma constante real c > 0 e uma constante inteira n >= 1 tais que f(n) <= cg(n) para todo inteiro n >= n0

### Exemplo Notação O

- Tempo de execução do algoritmo maxVetor: O(n)
- Justificativa:


> SE f(n) = 7n-2, A RELAÇÃO f(n) <= cg(n) VERIFICA, OU SEJA: 7n-2 <= 7n, PARA c = 7 E PARA n0 = 1

### Características

- Um algoritmo de ordenação é estável se preserva ordem relativa de itens com valores idêntocos.
- Quando um algoritmo não precisa de uma estrutura auxiliar (array, matriz, etc) é considerado In place ou In loco.



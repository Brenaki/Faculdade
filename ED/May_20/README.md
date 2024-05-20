# Algoritmo de Ordenação II

### Métodos de divisão e conquista

- São métodos que possuem a premissa de dividir o problema em subproblemas menores
- Normalmente são métodos recursivos
- Ao final os subproblemas são combinados novamente

#### Quick Sort 

- Dividir o vetor `X[p...r]` é particionado em dois subvetores não vazios `X[p...q]` e `X[q+1...r]`
- Cada elemento de `X[p...q]` é menor igual a `X[q+1...r]`
- O índice que é calculado como parte do processo de particionamento
- Normalmente o que é metade do vetor pé chamado de pivô
- Os elementos menores ou iguais ao pivô ficam a esquerda
- Os maiores do pivô ficam a direita
  - [Code](./quickSort.c)

#### Merge Sort 

- Dividir: divide a sequência de `n` elementos a serem ordenados em duas subsequência de `n/2` elementos cada
- Conquistar: ordena as duas subsequências recursivamente utilizando a ordenação por intercalação
- Combinar: intercalar as duas subsequência ordenadas para produzir a solução
  - [Code](./mergeSort.c)

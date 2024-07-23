# Algoritmos de busca II

### Estatística 

- Estatiscamente e por probabilidade existe uma chance maior de uma chave buscada ser buscada novamente;
- A chance disso aconntecer é maior quando o escopo de busca é pequeno;
- Logo fica evidente que, em uma busca sequencial, os elementos mais buscados fiquem próximo ao ínicio da lista torna o número de comparações menores.

#### Exemplo

- Após uma sequencia de busca em um vetor de inteiro chegamos a tabela a seguir:

Entrada | Frêquencia
:-- | --:
1 | 0.5
5 | 0.3
10 | 0.15
30 | 0.05
34 | 0.03

- Sequencial
  - Nc = N + 1 / 2
  - Nc = 5+1 / 2 = 6/2 => Nc = 3

> N -> número de elementos

```

      N
Nc = E i*freq 
      i=1


Nc = 1*0.5 + 2*0.3 + 3*0.15 + 4*0.05 + 5*0.03 = 1.9
```

### Mover para frente e transposição

- Como não é possível saber antecipadamente quais chaves serão mais buscadas, utilizamos duas técnicas chamadas:
  - Mover para Frente
  - Transposição

#### Transposição

- O algoritmo transposição consiste em:
  - Trocar a chave de busca pelo elemento imediatamente anterior no arranjo.

## Busca en tabelas ordenadas

- Nas tabelas ordenadas possuímos um ganho em números de comparações mais significativo;
- Na busca sequencial não existe a necessidade de percorrer toda tabela de busca, mas somente até encontrar a chave ou até o primeiro elemento maior que a chave de bsuca.

### Busca binária

- A busca binária só pode ser aplicada em tabelas ordenadas;
- É uma abordagem de divisão e conquista.


#### Exemplo buscando o número 7

0 | 1 | 2 | 3 | 4 | 5 | 6
:-- | :-: | :-: | :-: | :-: | :-: | --:
2 | 7 | 18 | 21 | 24 | 30 | 34

0 | 1 | 2 | 3
:-- | :-: | :-: | --:
2 | 7 | 18 | 21

0 | 1
:-- | --:
2 | 7

```c
int searchBinary(int *vet, int tam, int fim, int chave){
  int retorno;
  if(vet[fim] == chave){
    return 1;
  }
  
  if(vet[fim] > chave){
    retorno = searchBinary(vet, tam, fim/2, chave);
  } else {
    retorno = searchBinary(vet, tam, fim+1, chave);
  }
}
```

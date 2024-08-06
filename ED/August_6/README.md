# Tabela Hash

## Introdução

- A maioria das aplicações em computação são compostas por operações do tipo:
  - Inserção
  - Remoção
  - Consulta de dados

- Essas operações costumam ser na Ordem O(n)

- Uma tabela hashing é uma generalização de um vetor com `m` posições.
- Cada posição da tabela representa um endereço
- Os elementos a serem armazenados nela possuem um valor-chave que é utilizado para calcular o endereço na tabela onde serão alocados.

- Uma tabela de espalhamento de tamanho `m`
- Com endereço de 0 a `m-1`
- Dado um conjunto de `C` chaves
- Dado elementos `x` pertencendo a `C`

- Existe uma função de espalhamento que calcula o endereço onde `x` será armazenado
- A função de espalhamento reduz o espaço de endereços para armazenar os elementos de `C`

- A maioria das funções de hashing assume que os elementos-chave são números naturais
- Em resumo tabelas hashing são dicionários.

## Vantagens

- A principal vantagem está na busca pelos elementos na tabela.
- As operações podem chegar a ordem de O(1) mesmo no pior caso

## Uma boa função de hashing

- Deve gerar um número pequeno de colisões
- Ser facilmente computável

## Função hashing de divisão

- Uma chave `x` é mapeada em um dos `m` endereços calculando o resto da divisão de `x` por `m`
- `H(x) = x mod m`

- Exemplo
  - `m = 8, x = 100`
  - `100 mod 8 = 4`

## Tratando colisões

- Endereçamento aberto
  - Todas as chaves são armazenadas na própria tabela
  - Para números de chaves pequeno
  - Posições vazias da tabela são utilizadas para o tratamento de colisões
- Como encontrar as posições vazias?
  - Tentativa linear
  - Tentativa quadrática



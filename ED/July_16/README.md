# Algoritmos de Busca

### Problema

- Você possui um banco de dados com milhares de registros
- Você quer buscar um determinado elemento, quanto tempo vai levar?
- Já pensou como o banco de dados busca esses valores de forma relativamente rápida?

### Objetivos

- O objetivo da pesquisa é recuperar informações a patir de uma grande massa de informações previamente armazenada.

- A escolha do método de pesquisa mais adequado a determinada aplicação depende principalmente:
  - Quantidade de dados envolvidos;
  - O arquivo estar sujeitos a inserções e retiradas frequentes;
  - O conteúdo do arquivo ser praticamente estável.

## Busca sequencial

- É um algoritmo mais simples
- Consiste em percorrer a lista elemento a elemento até encontrar o registro igual a chave de pesquisa
- Basta percorrer do primeiro elemento até o último ou até encontrar o registro chave

- Pode ser implantado de duas maneiras
  - Retornar o elemento encontrado
  - Retornar o índice do elemento
- Ótimo para tabelas não ordenadas
  - Para tabelas ordenadas outros algoritmos podem ser melhores
  - Caso a tabela esteja ordenada a busca pode para quando encontrar um elemento maior que a chave
- Vimos esse algoritmo na busca por elemento em listas ordenadas

- Complexidade: O(n)

Caso | Melhor Caso | Pior Caso | Caso Médio
:-- | :-: | :-: | --:
Existe | 1 | n | n/2
Não Existe | n | n | n

- Uma forma de melhorar o desempenho (não necessariamente usa complexidade assintótica) é eleminando uma das comparações
- A cada passo que percorremos a tabela em uma busca sequencial fazemos uma comparação entre chave e registro, isso? Sim
- E se eleminarmos essa comparação?

- A ideia é muito simples
- O critério de parada da busca é a própria chave de busca
- Mas e se o elemento buscado não estiver na tabela, vamos ficar preso no loop?

- Para evitar esse problema, vamos simplesmente colocar a chave procurada no último índice da tabela
- Caso o elemento procurado for encontrado somente na última posição do vetor significa que o elemento não existe na tabela
- Como implemetar?
  - Criar um índice a mais na tabela
  - Substituir o último pela chave, mas antes verificar se ele não é o elemento procurado

- Vimos em árvore binária a possibilidade de inserir os elementos de forma que cada novo elemento inserido, a árvore se divide de acordo com o tamanho do novo elemento.

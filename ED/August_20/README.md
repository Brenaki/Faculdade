# Skip list

## Introdução

- Uma estrutura interessante para representação eficiente de um dicionário ordenado é a skip list.
- Nesta estrutura de dados, são feitas escolhas aleatórias ao arranjar os itens de tal forma que os tempos de pesquisa e de atualização são `O(log n)` em média, onde `n` é o número de itens no dicionário.

- Esta complexidade de tempo depende do uso de geradores de números pseudo-aleatório na implementação das inserções para auxiliar na decisão de onde colocar o novo item.
- Entretanto, este é o tempo "esperado" para a skip list, comparando com o pior caso para a busca com pesquisa binária.

## Skip list

- Proposta em 1990 por Bill Pugh
- Generalização da Lista Dinâmica Encadeada
- Listas Encadeadas consideram nós a frente e atrás

- Apenas o nível mais baixo contém todos os elementos
- Numa *skip list* perfeita, cada nó possui 1/2 dos nós do nível abaixo
- Pode-se substituir uma árvore balanceada, com vantagem da implementação ser mais simples
- Propriedades básicas como inserção remoção e busca tem ordem de `O(log n)`

- No seu pior caso `O(n)`, o que é muito raro, pois nesse caso busca deve iniciar no nivel mais baixo.

## Implementação

- Similar a uma lista encadeada
- Cada nó é um array de struct
- Esse array que faz a ligação entre os demais nós
- Devemos limitar previamente o tamanho de níveis que a skip poderá ter

### Implementação (Exemplos do Prof. André Backes)

```c
struct no {
  int chave;
  struct no **prox;
}

struct skiplist{
  int nivelMax;
  // Fração de nós
  float p;
  int nivel;
  struct no *inicio;
}
```

## Passo para criação da skip list

- Alocar espaço para o cabeçalho
- Alocar espaço para o primeiro nó e inicializar todos os níveis com NULL
- Primeiro nó define o menor valor a ser armazenado -1 para nosso caso

## Vamos usar duas funções para criação

- Criando a skiplist(cabeçalho)

```c
struct skiplist* criaSkip(int nivelMax, float p){
  struct skiplist *sk = (skiplist*)malloc(sizeof(struct skiplist));
  sk->nivelMax = nivelMax;
  sk->p = p;
  sk->nivel = 0;
  sk->nivel = novoNo(-1,nivelMax);
  return sk;
}
```

- Criando os nós

```c
struct no* novoNo(int chave, int nivel){
  struct no* novo = malloc(sizeof(struct no));
  novo->chave = chave;
  novo->prox = malloc((nivel+1)*sizeof(struct no*));
  int i;
  for(i=0;i<nivel+1;i++){
    novo->prox[i] = NULL;
  }
  return novo;
}
```

## Passos - Inserção

- Procurar a posição de inserção em cada nível da *Skip List* e armazenar em um array auxiliar.
- Alocar espaço para o novo nó e sortear quantos níveis ele terá.
- Se ele tiver mais níveis que a *Skip List*, atualizar os níveis do array auxiliar
- Fazer a ligação entre o array auxiliar e o novo nó, similar a lista dinâmica encadeada

```c
int sorteiaNivel(struct skiplist *sk){
  float r = (float)rand()/RAND_MAX;
  int nivel = 0;
  while(r < sk->p && nivel < sk->nivelMax){
    nivel++;
    r = (float)rand()/RAND_MAX;
  }
}

int insere(struct skiplist *sk, int chave){
  if(sk==NULL) return 0;
  int i;
  struct no *atual = sk->inicio;
  struct no **aux;
  aux = malloc((sk->nivelMax+1)*sizeof(struct no*));
  for(i=0;i<=sk->nivelMax;i++){
    aux[i] = NULL;
  }
  for(i=sk->nivel;i>=0;i--){
    while(atual->prox[i] != NULL && atual->prox[i]->chave < chave){
      atual = atual->prox[i];
    }
    aux[i] = atual;
  }
  atual = atual->prox[0];
  if(atual == NULL || atual->chave != chave){
    int novo_nivel = sorteiaNivel(sk);
    struct no* novo = novoNo(chave, novo_nivel);
  }
  // atualizando os niveis se novo nivel > sk->nivel

  if(novo_nivel > sk->nivel){
    for(i=sk->nivel+1;i<=novo_nivel;i++){
      aux[i] = sk->inicio;
    }
    sk->nivel = novo_nivel;
  }
  // inserindo o no
  for(i=0;i<novo_nivel;i++){
    novo->prox[i] = aux[i]->prox[i];
    aux[i]->prox[i] = novo;
  }
  free(aux);
  return 1;
}
```

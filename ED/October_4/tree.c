#include <stdio.h>
#include <stdlib.h>
#define ORDEM 200
#define MAX_CHAVES ORDEM-1
#define TOTAL 10000

struct Node {
  int dado[ORDEM-1];
  struct Node *filhos[ORDEM];
  struct Node *pai;
  int n_chaves;
};

struct Node *raiz = NULL;

int searchKey(struct Node *atual, int key){
  int i = 0;
  while(i < atual->n_chaves && key > atual->dado[i]){
    i++;
  }
  return i;
}

struct Node *findNode(int key, int *pos) {
  struct Node *atual, *ant;
  ant = NULL;
  atual = raiz;
  while (atual != NULL) {
    *pos = searchKey(atual, key);
    ant = atual;
    atual = atual->filhos[*pos];
  }
  return ant;
}

void insertLeaf(struct Node *atual, int key){
  int i;
  for(i = atual->n_chaves; i > 0 && key < atual->dado[i-1]; i--){
    atual->dado[i] = atual->dado[i-1];
  }
  atual->dado[i] = key;
  atual->n_chaves++;
}

struct Node *createNode(int key){
  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new->dado[0] = key;
  int i;
  for(i=1;i<ORDEM;i++){
    new->filhos[i] = NULL;
  }
  new->n_chaves = 1;
  return new;
}

int insertTree(int key){
  struct Node *new, *atual;
  int pos;
  if(raiz == NULL){
    raiz = createNode(key);
    return 1;
  }
  atual = findNode(key, &pos);
  if(atual->n_chaves < MAX_CHAVES){
    insertLeaf(atual, key);
    return 1;
  }
  new = createNode(key);
  atual->filhos[pos] = new;
  return 1;
}

int conta(struct Node *atual){
  int i, total;
  if(atual != NULL){
    total = 1;
    for(i=0; i < atual->n_chaves+1; i++){
      total = total + conta(atual->filhos[i]);
    }
    return total;
  }
  return 0;
}

void searchValue(int key) {
  struct Node *atual;
  atual = raiz;
  while (atual != NULL) {
    int pos = searchKey(atual, key);
    if(atual->dado[pos] == key){
      printf("\nValor encontrado!\n");
      return;
    } 
    atual = atual->filhos[pos];
  }
  printf("\nValor não encontrado!\n");
  return;
}

void walkInTree(struct Node *atual) {
  int i;
  if(atual != NULL){
    for(i=0;i<atual->n_chaves;i++){
      walkInTree(atual->filhos[i]);
      printf("%d ", atual->dado[i]);
    }
    walkInTree(atual->filhos[atual->n_chaves]);
  }
}

int main(){
  insertTree(13);
  insertTree(3);
  insertTree(19);
  insertTree(33);
  insertTree(91);
  insertTree(18);
  insertTree(2);
  printf("\n");
  walkInTree(raiz);
  searchValue(13);
  searchValue(43);
  printf("Count: %d\n", conta(raiz));
}

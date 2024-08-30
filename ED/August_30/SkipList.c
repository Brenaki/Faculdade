#include <stdlib.h>
#include <stdio.h>
#include "SkipList.h"
#define N 3

struct no {
  int chave;
  struct SkipList **prox;
};

struct SkipList {
  int nivelMax;
  float p;
  int nivel;
  struct no *inicio;
};

struct no* novoNo(int chave, int nivel){
  struct no* novo = malloc(sizeof(struct no));
  if(novo != NULL){
    novo->chave = chave;
    novo->prox = malloc((nivel+1)* sizeof(struct no*));
    int i;
    for(i=0;i<(nivel+1);i++)
      novo->prox[i] = NULL;
  }
  return novo;
}

SkipList *criaSkipList(int MAXLVL, float p){
  SkipList *sk = (SkipList*)malloc(sizeof(SkipList));
  if(sk != NULL){
    sk->nivelMax = MAXLVL;
    sk->p = p;
    sk->nivel = 0;
    sk->inicio = novoNo(-1, MAXLVL);
  }

  return sk;
}

int buscaSkipList(SkipList *sk, int chave){
  if(sk == NULL) return 0;
  struct no *atual = sk->inicio;
  int i;
  for(i=sk->nivel;i>=0;i--){
    while(atual->prox[i]!=NULL && atual->prox[i]->inicio->chave < chave)
      atual = atual->prox[i];
  }
  atual = atual->prox[0];
  if(atual != NULL && atual->chave == chave)
    return 1;
  else
    return 0;
}

int main(){
  SkipList *sk = criaSkipList(N, 0.5);
  
  return 0;
}

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

int sorteiaNivel(SkipList *sk){
  float r = (float)rand()/RAND_MAX;
  int nivel = 0;
  while(r<sk->p && nivel < sk->nivelMax){
    nivel++;
    r = (float)rand()/RAND_MAX;
  }
  return nivel;
}

int insereSkipList(SkipList *sk, int chave){
  if(sk == NULL) return 0;
  int i;
  struct no *atual = sk->inicio;
  struct no **aux;
  aux = malloc((sk->nivelMax+1)*sizeof(struct no*));
  for(i=0;i<=sk->nivelMax;i++)
    aux[i] = NULL;
  for(i=sk->nivel;i >= 0;i--){
    while(atual->prox[i] !=NULL && atual->prox[i]->inicio->chave < chave)
      atual = atual->prox[i];
    aux[i] = atual;
  }
  atual = atual->prox[0];

  if(atual == NULL || atual->chave != chave){
    int novoNivel = sorteiaNivel(sk);
    struct no *novo = novoNo(chave, novoNivel);
    if(novo == NULL){
      free(aux);
      return 0;
    }
    if(novoNivel > sk->nivel){
      for(i=sk->nivel+1;i<=novoNivel;i++)
        aux[i] = sk->inicio;
      sk->nivel = novoNivel;
    }
    for (i=0; i<= novoNivel; i++) {
      novo->prox[i] = aux[i]->prox[i];
      aux[i]->prox[i] = novo;
    }
    free(aux);
    return 1;
  }
  return -1;
}

int main(){
  SkipList *sk = criaSkipList(N, 0.5);
  int x = insereSkipList(sk, 10);  
  return 0;
}

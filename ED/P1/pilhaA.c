#include <stdio.h>
#include <stdlib.h>

struct no {
  int valor;
  struct no *prox;
};

struct no *pilha = NULL;

void push(int valor){
  struct no *aux;
  aux = (struct no*)malloc(sizeof(struct no));
  aux->valor = valor;
  aux->prox = pilha;
  pilha = aux;
  printf("\nElemento inserido\n");
}

int pop(){
  if(pilha == NULL){
    printf("\nA pilha está vazia!\n");
    return -1;
  }
  int num;
  struct no *aux;
  aux = pilha;
  num = aux->valor;
  pilha = aux->prox;
  free(aux);
  printf("\nElemento removido!\n");
  return num;
}

void imprime(){
  struct no *aux;
  printf("\nPilha: \n");
  for(aux=pilha;aux!=NULL;aux=aux->prox){
    printf("\t[%d]\n", aux->valor);
  }
  printf("\n");
}

void mostrarTopo(){
  if(pilha == NULL){
    printf("\nA pilha está vazia!\n");
    return;
  }
  printf("\nTopo da pilha: %d\n", pilha->valor);
}

int main(){
  push(13);
  push(18);
  push(21);
  push(30);
  imprime();
  pop();
  imprime();
  mostrarTopo();
  pop();
  pop();
  pop();
  pop();

  return 0;
}

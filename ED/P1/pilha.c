#include <stdio.h>

int top = 0, pilha[3];

int vazia(){
  if(top == 0){
    return 1;
  }
  return 0;
}

void push(int valor){
  if(top == 3){
    printf("\nA pilha está cheia!\n");
    return;
  }
  pilha[top] = valor;
  top++;
  printf("\nElemento inserido!\n");
  return;
}

int pop(){
  int valor;
  if(vazia() == 1){
    printf("\nA pilha está vazia!\n");
    return -1;
  }
  valor = pilha[top];
  top--;
  printf("\nElemento removido!\n");
  return valor;
}

void imprime(){
  printf("\nPilha:\n");
  for(int i=top;i>-1;i--){
    printf("\t[%d]\n", pilha[i]);
  }
  printf("\n");
}

void mostrarTopo(){
  if(vazia() == 1){
    printf("\nA pilha está vazia!\n");
    return;
  }
  printf("\nTopo da pilha: %d\n", pilha[top]);
}

int main(){
  push(13);
  push(18);
  push(21);
  push(30);
  pop();
  imprime();
  pop();
  mostrarTopo();
  pop();
  pop();

  return 0;
}

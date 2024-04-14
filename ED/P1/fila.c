#include <stdio.h>
#define TAM 3

int incio=0,fim=0,cont=0,fila[TAM];

int vazia(){
  if(cont == 0){
    return 1;
  }
  return 0;
}

void insere(int valor){
  if(cont == TAM){
    printf("\nA fila está cheia!\n");
    return;
  }
  cont++;
  fila[fim] = valor;
  if(fim == TAM-1){
    fim = 0;
  } else fim++;
  printf("\nElemento inserido!\n");
}

void remov(){
  if(vazia()==1){
    printf("\nA fila está vazia!\n");
    return;
  }
  cont--;
  if(incio == TAM-1){
    incio = 0;
  } else incio++;
  printf("\nElemento removido!\n");
}

void imprime(){
  int x=incio, y=0;
  if(vazia() == 1){
    printf("\nA fila está vazia!\n");
    return;
  }
  printf("\nFila: ");
  while(y<cont){
    printf("%d ", fila[x]);
    if(x == TAM-1){
      x = 0;
    } else x++;
    y++;
  }
    printf("\n");
}

void mostrarInicio(){
  printf("\nInicio da fila: %d\n", fila[incio]);
}

void mostrarFim(){
  printf("\nFim da fila: %d\n", fila[fim]);
}

int main(){
  insere(13);
  imprime();
  insere(18);
  imprime();
  insere(21);
  imprime();
  insere(30);
  imprime();
  remov();
  mostrarInicio();
  mostrarFim();
  remov();
  remov();
  remov();

  return 0;
}

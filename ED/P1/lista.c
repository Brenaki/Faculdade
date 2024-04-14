#include <stdio.h>
#define TAM 4

int lista[TAM], cont=0;

int vazia(){
  if(cont == 0){
    return 1;
  }
  return 0;
}

void insereLista(int valor){
  int i;
  if(cont == TAM){
    printf("\nA lista está cheia!\n");
    return;
  }
  for(i=cont;i>0&&valor<lista[i-1];i--){
    lista[i] = lista[i-1];
  }
  lista[i] = valor;
  cont++;
  printf("\nElemento inserido\n");
  return;
}

void recuperaLista(int pos){
  if(pos>=cont){
    printf("\nA posição é inválida\n");
    return;
  }
  printf("\nElemento da Posição %d: %d\n", pos, lista[pos]);
  return;
}

void removeValor(int valor){
  int i,j,achou=0;
  if(vazia() == 1){
    printf("\nA lista está vazia!\n");
    return;
  }
  for(i=0;i<cont&&valor>=lista[i];i++){
    if(valor == lista[i]){
      for (j=i;j<cont-1;j++) {
        lista[j] = lista[j+1];
      }
      cont--;
      printf("\nElemento removido!\n");
      achou = 1;
    }
  }
  if(achou == 0){
    printf("\nElemento não encontrado!\n");
    return;
  }
}

void removeLista(int pos){
  int i;
  if(pos>=cont){
    printf("\nA posição é inválida\n");
    return;
  }
  for(i=pos;i<=cont;i++){
    lista[i] = lista[i+1];
  }
  cont--;
  printf("\nElemento removido!\n");
  return;
}

void imprime(){
  if(vazia() == 1){
    printf("\nA lista está vazia!\n");
    return;
  }
  int i;
  printf("\nLista: ");
  for (i=0;i<cont;i++) {
    printf("%d ", lista[i]);
  }
  printf("\n\n");
}

int main(){
  insereLista(13);
  imprime();
  insereLista(18);
  recuperaLista(1);
  insereLista(21);
  imprime();
  insereLista(30);
  imprime();
  insereLista(24);
  removeLista(1);
  removeValor(13);

  return 0;
}

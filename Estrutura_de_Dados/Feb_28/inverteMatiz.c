#include <stdio.h>

void exibirMatriz(int v[][10], int x, int y){
  int n,z;
  for(n=0;n<x;n++){
    for(z=0;z<y;z++){
      printf("%d\t",v[n][z]);
    }
    printf("\n");
  }
}

void preencherMatriz(int v[][10], int x, int y){
  int n,z;
  for(n=0;n<x;n++){
    for(z=0;z<y;z++){
      v[n][z] = z+1;
    }
  }
}

int main(){
  int x,y;
  printf("Digite o tamanho da Matriz em x: ");
  scanf("%d",&x);
  fflush(stdin);
  printf("Digite o tamanho da Matriz em y: ");
  scanf("%d",&y);
  fflush(stdin);
  int i[x][y];
  preencherMatriz(i, x, y);
  // exibindo o vetor
  printf("exibindo o vetor\n");
  exibirMatriz(i, x, y);
  // invertendo a ordem

  // exibindo o vetor invertido
  printf("exibindo o vetor invertido\n");
  exibirMatriz(i, x, y);
  return 0;
}
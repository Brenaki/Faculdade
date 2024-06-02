#include <stdio.h>

int main() {
  // Declara uma matriz 2x3 (2 linhas, 3 colunas)
  int matriz[2][3];

  // Preenchendo a matriz 
  matriz[0][0] = 1;
  matriz[0][1] = 2;
  matriz[0][2] = 3;
  matriz[1][0] = 4;
  matriz[1][1] = 5;
  matriz[1][2] = 6;

  // Exibindo os elementos da matriz
  printf("Valores armazenados na matriz:\n");
  for (int linha = 0; linha < 2; linha++) {
    for (int coluna = 0; coluna < 3; coluna++) {
      printf("%d ", matriz[linha][coluna]);
    }
    printf("\n");
  }

  return 0;
}
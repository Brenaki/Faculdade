#include <stdio.h>

int main() {
  // Declara um vetor de inteiros com 5 posições
  int numeros[5];

  // Atribui valores a cada posição do vetor
  numeros[0] = 10;
  numeros[1] = 20;
  numeros[2] = 30;
  numeros[3] = 40;
  numeros[4] = 50;

  // Imprime os valores armazenados no vetor
  printf("Valores armazenados no vetor:\n");
  for (int i = 0; i < 5; i++) {
    printf("numeros[%d] = %d\n", i, numeros[i]);
  }

  return 0;
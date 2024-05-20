#include <stdio.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int array[], int esq, int dir) {
  int pivo = array[dir];
  int i = (esq - 1);

  for (int j = esq; j <= dir - 1; j++) {
    if (array[j] < pivo) {
      i++;
      troca(&array[i], &array[j]);
    }
  }
  troca(&array[i + 1], &array[dir]);
  return (i + 1);
}

void quickSort(int array[], int esq, int dir) {
  if (esq < dir) {
    int pi = particao(array, esq, dir);
    quickSort(array, esq, pi - 1);
    quickSort(array, pi + 1, dir);
  }
}

void imprimirArray(int array[], int tamanho) {
  for (int i = 0; i < tamanho; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main() {
  int array[] = {10,  7,  8,    9,   1,  5,  22,  4,   55,  67,  91, 1, 89,
                 100, 95, 2109, 782, 78, 61, 278, 567, 892, 567, 21, 73};
  int tamanho = sizeof(array) / sizeof(array[0]);
  quickSort(array, 0, tamanho - 1);
  printf("Array ordenado: \n");
  imprimirArray(array, tamanho);
  return 0;
}

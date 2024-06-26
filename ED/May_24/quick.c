#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 19999

int A[N];

void geraVetor() {
  int i;
  srand(13);
  for (i = 0; i < N; i++) {
    A[i] = rand() % (N * 13);
  }
}

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int array[], int baixo, int alto) {
  int pivo = array[alto];
  int i = (baixo - 1);

  for (int j = baixo; j <= alto - 1; j++) {
    if (array[j] < pivo) {
      i++;
      troca(&array[i], &array[j]);
    }
  }
  troca(&array[i + 1], &array[alto]);
  return (i + 1);
}

void quickSort(int array[], int baixo, int alto) {
  if (baixo < alto) {
    int pi = particao(array, baixo, alto);
    quickSort(array, baixo, pi - 1);
    quickSort(array, pi + 1, alto);
  }
}

void verficaVetor(clock_t t) {
  int aux = 0;
  for (int i = 0; i < N - 1; i++) {
    if (A[i] > A[i + 1])
      aux++;
  }
  if (aux == 0)
    printf("\nTempo de excecução: %.2f\n", (float)t / CLOCKS_PER_SEC);
  else
    printf("\nVetor não está ordenado!\n");
}

int main() {
  clock_t time1, time2;

  geraVetor();
  int tamanho = sizeof(A) / sizeof(A[0]);

  time1 = clock();
  quickSort(A, 0, tamanho - 1);
  time2 = (clock() - time1);
  verficaVetor(time2);

  time1 = clock();
  quickSort(A, 0, tamanho - 1);
  time2 = clock() - time1;
  verficaVetor(time2);
  return 0;
}

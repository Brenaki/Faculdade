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

void bubbleSort() {
  for (int i = 1; i <= N + 1; i++) {
    for (int j = 0; j <= N; j++) {
      if (A[j] > A[j + 1]) {
        int aux = A[j];
        A[j] = A[j + 1];
        A[j + 1] = aux;
      }
    }
  }
}

void bubbleSortTF() {
  for (int j = 1; j <= N - 1; j++) {
    for (int i = N - 1; i >= j; i--) {
      if (A[i] < A[i - 1]) {
        int aux = A[i];
        A[i] = A[i - 1];
        A[i - 1] = aux;
      }
    }
  }
}

void bubbleSortB() {
  int n = 1, troca = 1;

  while (n <= N && troca == 1) {
    troca = 0;
    for (int i = 0; i <= N - n - 1; i++) {
      if (A[i] > A[i + 1]) {
        int aux = A[i];
        A[i] = A[i + 1];
        A[i + 1] = aux;
        troca = 1;
      }
    }
    n = n + 1;
  }
}

void insertSort() {
  int pivo, j, x;
  for (int i = 1; i <= N - 1; i++) {
    pivo = A[i];
    j = i - 1;
    x = 0;
    while (x == 0 && j >= 0) {
      if (A[j] > pivo) {
        int aux = A[j];
        A[j + 1] = A[j];
        A[j] = aux;
        j--;
      } else
        x = 1;
    }
  }
}

void selectSort() {
  int i, k, aux, aux1;
  for (i = 0; i <= N - 1; i++) {
    aux = i;
    for (k = i + 1; k < N; k++) {
      if (A[aux] > A[k])
        aux = k;
    }
    aux1 = A[i];
    A[i] = A[aux];
    A[aux] = aux1;
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

  time1 = clock();
  // bubbleSort();
  // bubbleSortTF();
  // bubbleSortB();
  // insertSort();
  selectSort();
  time2 = (clock() - time1);
  verficaVetor(time2);

  time1 = clock();
  // bubbleSort();
  // bubbleSortTF();
  // bubbleSortB();
  // insertSort();
  selectSort();
  time2 = clock() - time1;
  verficaVetor(time2);
  return 0;
}

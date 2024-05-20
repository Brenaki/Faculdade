#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50000

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
    for (int i = 0; i < N; i++) {
      if (A[i] < A[i + 1]) {
        int aux = A[i];
        A[i] = A[i + 1];
        A[i + 1] = aux;
      }
    }
    n = n + 1;
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

void heapify(int arr[], int n, int i) {
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < n && arr[esquerda] > arr[maior])
    maior = esquerda;

  if (direita < n && arr[direita] > arr[maior])
    maior = direita;

  if (maior != i) {
    troca(&arr[i], &arr[maior]);
    heapify(arr, n, maior);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    troca(&arr[0], &arr[i]);
    heapify(arr, i, 0);
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
  // bubbleSort();
  // bubbleSortTF();
  // bubbleSortB();
  quickSort(A, 0, tamanho - 1);
  // heapSort(A, tamanho);
  time2 = (clock() - time1);
  verficaVetor(time2);

  time1 = clock();
  // bubbleSort();
  // bubbleSortTF();
  // bubbleSortB();
  quickSort(A, 0, tamanho - 1);
  // heapSort(A, tamanho);
  time2 = clock() - time1;
  verficaVetor(time2);
  return 0;
}

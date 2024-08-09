#include <stdio.h>
#define TAM 10

typedef struct {
  int values[TAM];
  int n;
} Heap;

void up(int n, int *values) {
  int i = n / 2;
  int aux;
  if (i >= 1) {
    if (values[n] < values[i]) {
      aux = values[n];
      values[n] = values[i];
      values[i] = aux;
      up(n, values);
    }
  }
}

void down(int n, int *values) {
  int i = 2 * n;
  int aux;

  if (i <= n) {
    if (i < n) {
      if (values[i + 1] < values[i]) {
        i++;
      }
    }
    if (values[n] > values[i]) {
      aux = values[n];
      values[n] = values[i];
      values[i] = aux;
      down(n, values);
    }
  }
}

void insertHeap(Heap vet, int value) {
  if (vet.n == TAM) {
    printf("\nHeap cheia\n");
    return;
  }

  vet.n++;
  vet.values[vet.n] = value;
  up(vet.n, vet.values);
  printf("\nElemento inserido com sucesso!\n");
}

void removeHeap(Heap vet) {
  int x;
  int aux;
  if (vet.n == 0) {
    printf("\nHeap vaiza!\n");
    return;
  }

  aux = vet.values[1];
  vet.values[1] = vet.values[vet.n];
  vet.values[vet.n] = aux;
  x = vet.n;
  vet.n--;
  down(1, vet.values);

  printf("\nRemovido com sucesso!\n");
}

void maxHeap(int *values) { printf("\nMaior valor: %d\n", values[1]); }

int main() {
  Heap vet;

  insertHeap(vet, 2);
  insertHeap(vet, 3);
  insertHeap(vet, 7);
  insertHeap(vet, 10);
  insertHeap(vet, 13);
  removeHeap(vet);
  maxHeap(vet.values);
  return 0;
}

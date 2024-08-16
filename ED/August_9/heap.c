#include <stdio.h>
#define TAM 10

typedef struct {
  int values[TAM + 1];
  int n;
} Heap;

void up(int *heap, int i) {
  int j;
  int aux;

  j = i / 2;
  if (j >= 1) {
    if (heap[i] > heap[j]) {
      aux = heap[i];
      heap[i] = heap[j];
      heap[j] = aux;
      up(heap, j);
    }
  }
}

void down(int i, Heap *heap) {
  int j;
  int aux;

  j = 2 * i;
  if (j <= heap->n) {
    if (j < heap->n) {
      if (heap->values[j + 1] > heap->values[j]) {
        j++;
      }
    }
    if (heap->values[i] < heap->values[j]) {
      aux = heap->values[i];
      heap->values[i] = heap->values[j];
      heap->values[j] = aux;
    }
    down(j, heap);
  }
}

void insertHeap(Heap *heap, int value) {
  if (heap->n == TAM) {
    printf("\nHeap cheia\n");
    return;
  }

  heap->n++;
  heap->values[heap->n] = value;
  up(heap->values, heap->n);
  printf("\nElemento inserido com sucesso!\n");
}

void removeHeap(Heap *vet) {
  int x;
  int aux;
  if (vet->n == 0) {
    printf("\nHeap vaiza!\n");
    return;
  }

  aux = vet->values[1];
  vet->values[1] = vet->values[vet->n];
  vet->values[vet->n] = aux;
  x = vet->n;
  vet->n--;
  down(1, vet);

  printf("\nRemovido com sucesso!\n");
}

void maxHeap(int *values) { printf("\nMaior valor: %d\n", values[1]); }

void printAll(Heap *heap) {
  int i;
  for (i = 1; i <= heap->n; i++) {
    printf("%d ", heap->values[i]);
  }
}

int main() {
  Heap vet;
  vet.n = 0;

  insertHeap(&vet, 13);
  insertHeap(&vet, 3);
  insertHeap(&vet, 7);
  insertHeap(&vet, 10);
  insertHeap(&vet, 16);
  insertHeap(&vet, 5);
  printAll(&vet);
  maxHeap(vet.values);
  removeHeap(&vet);
  printAll(&vet);
  maxHeap(vet.values);
  return 0;
}

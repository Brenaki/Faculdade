#include <stdio.h>
#include <stdlib.h>
#define N 200

typedef struct {
  int values[N+1];
  int size;
} Heap;

int randomNumber(int count){
    int num;
    srand(13);
    num = rand() % count;
    return num;
}

void generateFile(){
    FILE *file;
    file = fopen("numbers.txt", "w");
    for(int i = 0; i < N; i++){
        fprintf(file, "%d\n", randomNumber(N));
    }
    fclose(file);
}

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
  if (j <= heap->size) {
    if (j < heap->size) {
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

void insertHeap(Heap *heap, int *value) {
  if (heap->size == N) {
    printf("\nHeap cheia\n");
    return;
  }

  heap->size++;
  heap->values[heap->size] = *value;
  up(heap->values, heap->size);
}

void removeHeap(Heap *vet) {
  int x;
  int aux;
  if (vet->size == 0) {
    printf("\nHeap vaiza!\n");
    return;
  }

  aux = vet->values[1];
  vet->values[1] = vet->values[vet->size];
  vet->values[vet->size] = aux;
  x = vet->size;
  vet->size--;
  down(1, vet);
}

void generateHeap(Heap *heap) {
    FILE *file;
    int *aux;
    file = fopen("numbers.txt", "r");
    for(int i = 0; i < N; i++){
        fseek(file, i, SEEK_SET);
        fread(aux, sizeof(int), 1, file);
        insertHeap(heap, aux);
    }
    fclose(file);
}

void cls(){
    system("cls");
}

void pause(){
    system("pause");
}

void addHeap(){
  cls();
}
// void removeHeap(){}
void printHeap(Heap *heap) {
  int i;
  for (i = 1; i <= heap->size; i++) {
    printf("%d ", heap->values[i]);
  }
}

void menu(Heap *heap) {
  cls();
  int choose;
  printf("Choose an option:\n1 - Add numero na heap\n2 - Remove numero da heap\n3 - Imprimir heap\n4 - Sair\n");
  scanf("%d", &choose);
  switch (choose) {
    case 1:
      addHeap();
      break;
    case 2:
      // removeHeap();
      break;
    case 3:
      printHeap(heap);
      break;
    case 4:
      return;
    default:
      printf("Invalid option\n");
      break;
  }
}

int main() {
  Heap vet;
  vet.size = 0;
  generateFile();
  generateHeap(&vet);
  menu(&vet);

  return 0;
}
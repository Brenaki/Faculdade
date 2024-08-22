#include <stdio.h>
#include <stdlib.h>
#define N 300

typedef struct {
  int values[N + 1];
  int size;
} Heap;

void menu(Heap *heap);

int randomNumber(int count) {
  int num;
  srand(2);
  num = rand() % count;
  return num;
}

void generateFile() {
  FILE *file;
  file = fopen("numbers.txt", "w");
  for (int i = 1; i < 201; i++) {
    fprintf(file, "%d\n", randomNumber(i));
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
  int aux;
  file = fopen("numbers.txt", "r");
  for (int i = 0; i < 200; i++) {
    if (fscanf(file, "%d", &aux) != 1) {
      printf("\nErro em ler o arquivo!\n");
      fclose(file);
      return;
    }
    insertHeap(heap, &aux);
  }
  fclose(file);
}

void cls() {
  if (system("cls") != 0) {
    system("clear");
  } else {
    system("cls");
  }
}

void pause() {
  if (system("pause") != 0) {
    system("echo \"Aguarde 3 segundos...\"");
    system("sleep 3");
  } else {
    system("pause");
  }
}

void printHeap(Heap *heap) {
  int i;
  for (i = 1; i <= heap->size; i++) {
    printf("%d ", heap->values[i]);
  }
  printf("\n");
  pause();
  cls();
  return;
}

void maxNums(Heap *heap) {
  printf("Top 3 maiores numeros da HEAP:\n");
  for (int i = 0; i < 3; i++) {
    printf("%d: %d\n", i + 1, heap->values[i + 1]);
  }
}

void menu(Heap *heap) {
  int choose = 0, num;
  while (choose != 7) {
    cls();
    printf(
        "Choose an option:\n1 - Add numero na heap\n2 - Remove numero da "
        "heap\n3 - Imprimir heap\n4 - Gerar o txt\n5 - Colocar os números "
        "do arquivo na heap\n6 - 3 Maiores numero da heap\n7 - Sair\n\nVocê: ");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
      cls();
      printf("Qual numero deseja inserir na heap: ");
      scanf("%d", &num);
      insertHeap(heap, &num);
      system("echo \"Elemento Inserido!\"");
      break;
    case 2:
      cls();
      removeHeap(heap);
      system("echo \"Elemento Removido!\"");
      pause();
      break;
    case 3:
      cls();
      printHeap(heap);
      cls();
      break;
    case 4:
      cls();
      generateFile();
      printf("Arquivo gerado!\n");
      pause();
      break;
    case 5:
      cls();
      generateHeap(heap);
      printf("Numeros do arquivos estão na heap!\n");
      pause();
      break;
    case 6:
      cls();
      maxNums(heap);
      pause();
      break;
    case 7:
      cls();
      break;
    default:
      printf("Invalid option\n");
      break;
    }
  }
}

int main() {
  Heap vet;
  vet.size = 0;
  menu(&vet);
  return 0;
}

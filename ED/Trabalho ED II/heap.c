/*
* Nome dos Integrantes da dupla:
* João Pedro Borsato de Ramos
* Victor Angelo Legat Cerqueira
*/

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
    printf("\nSistema: Heap cheia\n");
    return;
  }

  heap->size++;
  heap->values[heap->size] = *value;
  up(heap->values, heap->size);
  system("echo \"Sistema: Elemento Inserido!\"");
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
  system("echo \"Sistema: Elemento Removido!\"");
}

void generateHeap(Heap *heap) {
  FILE *file;
  int aux;
  file = fopen("numbers.txt", "r");
  for (int i = 0; i < 200; i++) {
    if (fscanf(file, "%d", &aux) != 1) {
      printf("\nSistema: Erro em ler o arquivo!\n");
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
  int res = system("pause");

  if (res != 0) {
    system("echo \"Sistema: Aguarde 3 segundos...\"");
    system("sleep 3");
  }
}

void printHeap(Heap *heap) {
  int i;
  printf("Sistema: HEAP\n");
  for (i = 1; i <= heap->size; i++) {
    printf("%d ", heap->values[i]);
  }
  printf("\n");
  pause();
  cls();
  return;
}

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxNums(Heap *heap) {
  int top3[3] = {0, 0, 0};

  for (int i = 1; i <= heap->size; i++) {
    if (heap->values[i] > top3[2]) {
      top3[2] = heap->values[i];
      if (top3[1] < top3[2]) {
        troca(&top3[1], &top3[2]);
      }
      if (top3[0] < top3[1]) {
        troca(&top3[0], &top3[1]);
      }
    }
  }

  printf("Sistema: Top 3 maiores números da HEAP:\n");
  for (int i = 0; i < 3; i++) {
    printf("%d: %d\n", i, top3[i]);
  }
}

void menu(Heap *heap) {
  int choose = 0, num;
  while (choose != 7) {
    cls();
    printf("Escolha uma opção:\n1 - Add numero na heap\n2 - Remove número da "
           "heap\n3 - Imprimir heap\n4 - Gerar o txt\n5 - Colocar os números "
           "do arquivo na heap\n6 - Top 3 da heap\n7 - Sair\n\nVocê: ");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
      cls();
      printf("Sistema: Qual numero deseja inserir na heap?\n");
      scanf("%d", &num);
      insertHeap(heap, &num);
      pause();
      break;
    case 2:
      cls();
      removeHeap(heap);
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
      printf("Sistema: Arquivo gerado!\n");
      pause();
      break;
    case 5:
      cls();
      generateHeap(heap);
      printf("Sistema: Numeros do arquivos estão na heap!\n");
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
      printf("Sistema: Opção inválida\n");
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

#include <stdio.h>
#define N 13
// N must be a prime number

typedef struct {
  // r = remove
  // f = free
  // b = busy
  char key;
  int value;
} Hash;

void fillVetor(Hash *v) {
  for (int i = 0; i < N; i++) {
    v[i].key = 'f';
  }
}

void addItem(Hash *v, int value) {
  int mod = value % N;
  for (int i = mod; i < N; i++) {
    if (v[i].value == value) {
      printf("\n\nNão pode ser inserido número repetido\n\n");
      return;
    }
    if (v[i].key != 'b') {
      v[i].value = value;
      v[i].key = 'b';
      printf("\n\nElemento inserido\n\n");
      return;
    }
    if (i == N - 1) {
      i = 0;
    }
    if (mod - 1 == i) {
      printf("\nArray cheia!\n");
      return;
    }
  }
}

void removeItem(Hash *v, int value) {
  int mod = value % N;
  for (int i = mod; i < N; i++) {
    if (v[i].value == value && v[i].key == 'b') {
      v[mod].key = 'r';
      printf("\n\nElemento removido\n\n");
      return;
    }
    if (i == N - 1) {
      i = 0;
    }
    if (i == mod - 1) {
      printf("\n\nEsse elemento não foi encontrado para ser removido\n\n");
      return;
    }
  }
}

void searchItem(Hash *v, int value) {
  int mod = value % N;
  for (int i = mod; i < N; i++) {
    if (v[i].value == value && v[i].key == 'b') {
      printf("\nO valor foi encontrado:\nKey: %c\tValue: %d\n", v[mod].key,
             v[mod].value);
      return;
    }
    if (i == N - 1) {
      i = 0;
    }
    if (i == mod - 1) {
      printf("\n\nEsse elemento não foi encontrado\n\n");
      return;
    }
  }
}

void printItems(Hash *v) {
  for (int i = 0; i < N; i++) {
    if (v[i].key == 'b') {
      printf("Index: %d\tValue: %d\n", i, v[i].value);
    }
  }
}

int main() {
  Hash vet[N];
  addItem(vet, 3);
  addItem(vet, 3);
  addItem(vet, 4);
  addItem(vet, 18);
  printItems(vet);
  removeItem(vet, 18);
  removeItem(vet, 18);
  printItems(vet);
  searchItem(vet, 4);
  searchItem(vet, 18);

  return 0;
}

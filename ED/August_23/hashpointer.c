#include <stdio.h>
#include <stdlib.h>
#define N 13

struct Hash {
  int value;
  struct Hash *prox;
};

struct Hash *hash[N];

int position(int value) { return value % N; }

void insereHash(int value) {
  struct Hash *aux;
  int pos = position(value);
  aux = (struct Hash *)malloc(sizeof(struct Hash));
  aux->value = value;
  aux->prox = hash[pos];
  hash[pos] = aux;
  printf("\nElemento inserido na Hash!\n");
}

void searchHash(int value) {
  struct Hash *aux;
  int achou = 0;
  int pos = position(value);
  for (aux = hash[pos]; aux != NULL; aux = aux->prox) {
    if (value == aux->value) {
      printf("\nNumero encontrado: %d\n", aux->value);
      return;
    }
  }
  if (achou == 0) {
    printf("\nNumero não encontrado!\n");
  }
}

void printHash() {
  struct Hash *aux;
  for (int i = 0; i < N; i++) {
    if (hash[i] != NULL) {
      printf("[");
      for (aux = hash[i]; aux != NULL; aux = aux->prox) {
        printf(" %d", aux->value);
      }
      printf(" ]\n");
    }
  }
  system("sleep 3") || system("pause");
}

void addHash() {
  int num, aux = 0, n;
  printf("Quantos numeros você deseja inserir: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("\nInsira o %d numero na Hash: ", i + 1);
    scanf("%d", &num);
    if (aux != num) {
      insereHash(num);
      aux = num;
    } else {
      printf("\nNumero repetido!\n");
      i--;
    }
  }
  system("sleep 3") || system("pause");
}

void searchInHash() {
  int num;
  printf("\nQual numero voce deseja buscar: \n");
  scanf("%d", &num);
  searchHash(num);
  system("sleep 3") || system("pause");
}

void menu() {
  int choose;
  do {
    system("clear") || system("cls");
    printf("\nEscolha uma opcao\n1 - Inserir Numero\n2 - Imprimir Hash\n3 - "
           "Buscar Numero na Hash\n4 - Sair\n\nVoce: ");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
      addHash();
      break;
    case 2:
      printHash();
      break;
    case 3:
      searchInHash();
      break;
    case 4:
      break;
    }
  } while (choose != 4);
}

int main() {
  menu();
  return 0;
}

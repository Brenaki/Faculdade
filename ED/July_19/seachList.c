#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20001
#define N 1000

int vet[TAM];

void gerarVet() {
  int i;
  srand(13);
  for (i = 0; i < TAM; i++) {
    vet[i] = rand() % (TAM * 13);
  }
}

void linearSeach(int *numbers, int n) {
  clock_t time1, time2;
  int i, j, achou = 0;

  time1 = clock();
  for (i = 0; i < n; i++) {
    for (j = 0; j < TAM; j++) {
      if (numbers[i] == vet[j]) {
        achou++;
      }
    }
  }
  time2 = (clock() - time1);
  printf("Números encontrados\tNúmeros não "
         "encontrados\tTempo\n%d\t\t\t%d\t\t\t%.2f\n\n",
         achou, (n - achou), (float)time2 / CLOCKS_PER_SEC);
}

void sentinelaSeach(int numbers[], int n) {
  clock_t time1, time2;
  int i = 0, j = 0, achou = 0;

  time1 = clock();
  while (j < TAM) {
    vet[TAM - 1] = numbers[i];
    while (numbers[i] != vet[j]) {
      j++;
    }
    i++;
  }

  time2 = (clock() - time1);
  printf("Números encontrados\tNúmeros não "
         "encontrados\tTempo\n%d\t\t\t%d\t\t\t%.2f\n\n",
         achou, (n - achou), (float)time2 / CLOCKS_PER_SEC);
}

int main() {
  // Part 1
  gerarVet();
  int numbers[N];
  int n;
  for (n = 0; n < N; n++) {
    numbers[n] = rand() % (N * 11);
  }

  // Linear Seach
  linearSeach(numbers, N);

  for (n = 0; n < N; n++) {
    numbers[n] = rand() % (N * 15);
  }
  // Sentinela Seach
  sentinelaSeach(numbers, N);
  return 0;
}

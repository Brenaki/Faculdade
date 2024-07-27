#include <stdio.h>

// 1 <= N <= 500 000 -> Tamanho do vetor
// 0 <= K <= 10^6 -> Soma dos números
// 0 <= Xi <= 100 -> Números dentro do vetor

void retangulo(int *arr, int n, int k) {
  int i, j, soma, solucao = 0;
  for (i = 0; i < n - 1; i++) {
    soma = 0;
    for (j = i; j < n - 1; j++) {
      soma += arr[j];
      if (soma > k) {
        break;
      }
      if (soma == k)
        solucao++;
    }
  }

  printf("%d", solucao);
}

int main() {
  int k, n;
  scanf("%d", &n);
  scanf("%d", &k);

  int arr[n];

  for (int i; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  retangulo(arr, n, k);

  return 0;
}

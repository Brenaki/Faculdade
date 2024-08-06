#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k, i, sum = 0, count = 0;

  // Lendo N e K
  printf("N e K: ");
  scanf("%d %d", &n, &k);

  // Alocando memória para o vetor
  int *vet = (int *)malloc(n * sizeof(int));

  // Lendo o vetor
  printf("Vetor: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  // Implementando a lógica do dicionário usando um array (considerando valores
  // pequenos)
  int maxSum = k + 1000000; // Ajustar se necessário
  int *dic = (int *)calloc(maxSum, sizeof(int));
  dic[0] = 1;

  for (i = 0; i < n; i++) {
    sum += vet[i];

    // Verificando se (sum - k) existe no "dicionário"
    if (sum - k >= 0 && dic[sum - k] > 0) {
      count += dic[sum - k];
    }

    // Incrementando a contagem no "dicionário"
    if (sum < maxSum) {
      dic[sum]++;
    }
  }

  printf("%d\n", count);

  free(vet);
  free(dic);
  return 0;
}

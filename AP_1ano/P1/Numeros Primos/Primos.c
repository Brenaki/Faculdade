#include <stdio.h>

int main() {
  int i, j, div, somaPrimo;
  somaPrimo = 0;

  for (i = 1; i <= 1000; i++) {
    div = 0;
    for (j = 2; j <= i; j++) {
      if (i % j == 0) {
        div++;
      }
    }
    if (div == 1) {
      somaPrimo += i;
    }
  }

  printf("A soma de todos os números primos é: %d\n", somaPrimo);

  return 0;
}
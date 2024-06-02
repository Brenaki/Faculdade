#include <stdio.h>

// Função para calcular a soma de dois números
int soma(int a, int b) {
  int resultado = a + b;
  return resultado; // Retorna o valor da soma
}

int main() {
  int num1 = 5, num2 = 3;
  int resultado_soma;

  resultado_soma = soma(num1, num2); // Chama a função 'soma'

  printf("A soma de %d e %d é %d\n", num1, num2, resultado_soma);

  return 0;
}
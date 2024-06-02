#include <stdio.h>

int main() {
  int num = 5;
  int *ptr = &num; // 'ptr' aponta para 'num'

  printf("Valor de 'num': %d\n", num);
  printf("Endereço de 'num': %p\n", &num);
  printf("Valor de 'ptr': %p\n", ptr); // Mostra o endereço armazenado
  printf("Conteúdo apontado por 'ptr': %d\n", *ptr);

  return 0;
}
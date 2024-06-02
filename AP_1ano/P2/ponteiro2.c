#include <stdio.h>

void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
  int a = 13, b = 6;
  printf("Elementos antes da troca:\nA:%d\tB:%d", a, b);
  troca(&a, &b);
  printf("Elementos depois da troca:\nA:%d\tB:%d", a, b);

  return 0;
}
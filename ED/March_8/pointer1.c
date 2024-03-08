#include <stdio.h>

void charge(int * a, int * b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int a, b;
	int *ptr_a, *ptr_b;
	
	a = 3;
	b = 13;
	ptr_a = &a;
	ptr_b = &b;
	
	printf("\nAntes da alterar os valores:\n");
	printf("A: %d\tB: %d", *ptr_a, *ptr_b);
	charge(ptr_a, ptr_b);
	printf("\nDepois de alterar os valores:\n");
	printf("A: %d\tB: %d", *ptr_a, *ptr_b);

	return 0;
}

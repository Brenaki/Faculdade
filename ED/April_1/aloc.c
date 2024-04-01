#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *ptr;
	printf("\nEndereço: %p\n", ptr);
	ptr = (int *) malloc(sizeof(int));
	*ptr = 13;
	printf("\nValor: %d\tEndereço: %p\n", *ptr, ptr);
	
	free(ptr);
	return 0;
}

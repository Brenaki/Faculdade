#include <stdio.h>
#include <stdlib.h>

int pot(int n1, int n2){
	if(n2 == 0){
		return 1;
	}
	return pot(n1, n2-1) * n1;
}

int main(){
	int tam;
	int *var;
	printf("Digite o valor do tamanho da variável: ");
	scanf("%d", &tam);
	var = (int *) malloc(sizeof(int)*tam);

	for(int i = 0; i<tam; i++){
		var[i] = pot(i+1, 2);
		printf("\nPosição %d: %d\n", i, var[i]);
	}

	return 0;
}

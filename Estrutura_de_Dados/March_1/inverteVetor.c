#include <stdio.h>

void exibir(int v[], int n){
	int y;
	for(y=0;y<n;y++){
		printf("%d\n",v[y]);
	}
}

void inverter(int v[], int n){
	int y,z;
	for(y=0;y<n/2;y++){
		z = v[y];
		v[y] = v[(n-1)-y];
		v[(n-1)-y] = z;
	}
}

void preencherVetor(int v[], int n){
	int y;
	for(y=0;y<n;y++){
		v[y] = y+1;
	}
}

int main(){
	int n;
	printf("Digite o tamano do vetor: ");
	scanf("%d",&n);
	fflush(stdin);
	int x[n];
	preencherVetor(x, n);
	// exibindo o vetor
	printf("exibindo o vetor\n");
	exibir(x, n);
	// invertendo a ordem
	inverter(x, n);
	// exibindo o vetor invertido
	printf("exibindo o vetor invertido\n");
	exibir(x, n);
return 0;
}

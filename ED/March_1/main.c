#include <stdio.h>

void exibir(int v[]){
	int y;
	for(y=0;y<10;y++){
		printf("%d\n",v[y]);
	}
}

void inverter(int v1[], int v2[]){
	int y,z;
	for(y=0;y<5;y++){
		z = v1[y];
		v2[y] = v1[(10-1)-y];
		v2[(10-1)-y] = z;
	}
}

void selecao(int *p, int a[], int b[]){
	int i, t = 0;
	for(i=0;i<10;i++){
		if(a[i] > *p){
			b[t] = a[i];
			t++;
		}
	}
	printf("\nVetor B: ");
	for(i=0;i<t;i++){
		printf("%d ", b[i]);
	}
}

void igualValor(int* p, int v1[]){
	int i,apareceu = 0, j=0;
	printf("\nE nas posicoes: ");
	for(i=0;i<10;i++){
		if(v1[i] == *p){	
			apareceu++;
			j++;
			printf("%d, ", i);
		}
	}
	if(apareceu > 0){
		printf("\nO valor %d apareceu tantas %d vezes", *p,apareceu);
	}
	else {
		printf("Esse valor digitado n�o foi encontrado!");
	}
}

void maiorEMenor(int v1[]){
	int i,j, menor = v1[0], maior = v1[0];
	for(i=0;i<10;i++){
		if(v1[i] > maior){
            maior = v1[i];
        }
        if(v1[i] < menor){
            menor = v1[i];
        }
	}
	printf("\nO maior numero e: %d\nO menor numero e: %d", maior, menor);
}

void media(int v1[]){
	int i;
	float m;
	for(i=0;i<10;i++){
		m += v1[i];
	}
	m /= 10;
	printf("\nMedia dos valores e %3.2f\n", m);
}

int main(){
	// criando vetores
	int v1[10], v2[10], a[10], b[10];
	int i,p;

	// preenchendo o vetor
	for(i=0;i<10;i++){
		printf("Digite o numero na posicao %d do vetor: ", i+1);
		scanf("%d",&v1[i]);
		fflush(stdin);
	}

	// exibindo o vetor
	printf("\nExibindo o vetor\n");
	exibir(v1);

	// invertendo a ordem
	inverter(v1, v2);

	// exibindo o vetor invertido
	printf("\nExibindo o vetor invertido\n");
	exibir(v2);

	// maior e menor valor
	maiorEMenor(v1);
	
	// busque um valor no vetor
	printf("\nDigite um valor que deseja procurar no vetor: \n");
	scanf("%d", &p);
	fflush(stdin);
	igualValor(&p, v1);
	
	// media entre os valores
	media(v1);
	
	// preenchendo o vetor
	for(i=0;i<10;i++){
		printf("\nDigite o numero na posicao %d do vetor: ", i+1);
		scanf("%d",&a[i]);
		fflush(stdin);
	}
	
	printf("\nDigite um valor para tranferir para vetor B: \n");
	scanf("%d", &p);
	fflush(stdin);
	
	// maior q o numero digitado
	selecao(&p, a, b);
	
	return 0;
}

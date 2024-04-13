#include <stdio.h>

typedef struct {
	int id;
	char descrip[50];
	float price;
	int un;
} Loja;

int main(){
	Loja prod[5];
	printf("INSIRA OS 5 PRODUTOS:\n");
	for(int i = 0; i < 5; i++){
		printf("\nDigite o id do %d produto: ", i+1);
		scanf("%d", &prod[i].id);
		fflush(stdin);
		printf("\nDigite o descrição do %d produto: ", i+1);
		scanf("%s", prod[i].descrip);
		fflush(stdin);
		printf("\nDigite o preço do %d produto: ", i+1);
		scanf("%f", &prod[i].price);
		fflush(stdin);
		printf("\nDigite o saldo do %d produto: ", i+1);
		scanf("%d", &prod[i].un);
		fflush(stdin);
	}
	printf("\nID\tDescrição\tPreço\tUnidades\n");
	for(int i = 0; i<5; i++){
		printf("%d\t%s\t%3.2f\t%d\n", prod[i].id, prod[i].descrip, prod[i].price, prod[i].un);
	}
	return 0;
}

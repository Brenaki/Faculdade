# include <stdio.h>
# include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");

	float a,b,c;

	printf("==============================================================\n");
	printf("Informe os lados A, B e C do triângulo: \n");
	scanf("%f %f %f", &a,&b,&c);

	if (a<b+c && b<a+c && c<a+b){
    		if (a==c && b == c){
        		printf("Triângulo Equilátero.");
    		}
    		else if (a!=c && b!=a && b!=c){
        		printf("Triângulo Escaleno.");
    		}
    		else if(a == b && a != c || a == c && a != b || c == b && c != a){
        		printf("Triângulo Isósceles.");
    		}
	} else printf("Não corresponde a um triângulo!");
	printf("\n==============================================================");
	return 0;
}

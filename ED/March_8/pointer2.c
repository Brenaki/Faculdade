#include <stdio.h>


float finalScore(float *notas){
	float score;
	for(int i = 0; i < 5; i++){
		score += notas[i];
	}
	score /= 5;
	return score;	
}


int main(){
	float notas[5];
	for(int i = 0; i < 5; i++){
		printf("Insira a %d nota: ", i+1);
		scanf("%f", &notas[i]);
	}
	printf("\nMédia final: %3.2f", finalScore(notas));
	return 0;
}

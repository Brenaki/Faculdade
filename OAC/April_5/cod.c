#include <stdio.h>

int main(){
	int x[9] = {0,1,12,3,5,8,15,2,1};
	int maior = 0;
	
	for(int i=0;i<9;i++){
		if(x[i]>maior){
			maior = x[i];
		}
	}

	printf("%d", maior);
	return 0;
}

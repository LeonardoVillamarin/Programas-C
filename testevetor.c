#include <stdio.h>

int main(){
	int vetor[8] = {1,2,4,4,4,5,7,6};
	int i,j;
	int contador=8;
	int x;
	for(i=0; i<contador; i++){
		printf("%d",vetor[i]);
	}
	printf("\n");
	for(i=0; i<contador; i++){
		if(vetor[i]%2!=0){
			for(j=i; j<contador; j++){
				vetor[j]=vetor[j+1];
			}
			contador--;
			i--;	
		}
	}
	for(j=0; j<contador; j++){
			printf("%d",vetor[j]);
	}
	printf("\n");
	
	return 0;
}
#include <stdio.h>

int main(){
	int vetor[10]={4,7,6,9,8,20,13,12,2,15};
	int maiores[3];
	int maior,i,j,x=0,indice=0;

	for(i=0; i<10; i++){
		maior=vetor[i];
		for(j=9; j>0; j--){
			if(maior<vetor[j]){
				maior=vetor[j];
				indice=j;
			}
			else
				vetor[i]=0;	
		}
		vetor[indice]=0;
		if(x<3){
			maiores[x]=maior;
			x++;
			}	
	}
	for(i=0; i<3; i++){
		printf("%d\n", maiores[i]);
	}
	return 0;
}

#include <stdio.h>

int Pa(int *vetor){
	int variavel = 1;
	int razao = vetor[1]-vetor[0];
	for(int i=0; i<5; i++){
		if(razao != vetor[i+1]-vetor[i]){
			variavel = 0;
		}
	}
	return variavel;
}
int Pg(int *vetor){
	int razao = vetor[1]/vetor[0];
	int variavel = 1;
	for(int i=0; i<5; i++){
		if(razao != vetor[i+1]/vetor[i]){
			variavel = 0;
		}
	}
	return variavel;	
}

int main(){
	int vetor[6] = {2,4,8,16,32,64};
	if(Pa(vetor)==1){
		printf("É uma PA\n");
	}
	else if(Pg(vetor)==1){
		printf("É uma PG\n");
	}
	else{
		printf("Não é nada\n");
	}
	return 0;
}
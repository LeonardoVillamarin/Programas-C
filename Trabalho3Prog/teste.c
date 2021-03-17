#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *nome;
	char *copia;
	int numero;
	printf("Digite algo:\n");
	scanf("%s", nome);
	fprintf(stderr,"Hmmm\n");

	printf("Digite um numero:\n");
	scanf("%d", &numero);
	int i=1;
	do{
		i++;
		nome++;
		if(i==numero){
			printf("Esse: %c\n",*nome);
			nome-=i-1;
		}
	}while(i!=numero);
	
	printf("%s\n",nome);
	//printf("%s\n",copia);
	return 0;
}
#include <stdio.h>

int main(){
	char numero[100];
	printf("Digit um numero:\n");
	scanf("%s",numero);
	int i=0,j=0,indice=0;
	char aux;
	while(numero[i]!='\0'){
		while(numero[indice]!='\0'){
			indice++;
		}
		for(int z=0; z<(indice/2); z++){
			int x = indice;
			aux = numero[z];
			numero[z] = numero[x];
			numero[x] = aux;
			x--;
		}	
		i++;
	}
	while(numero[j]!='\0'){
		printf("%c", numero[j]);
		j++;
	}
	printf("\n");
	return 0;
}

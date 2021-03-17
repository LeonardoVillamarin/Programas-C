#include <stdio.h>

int main(){
	int n1,n2;
	printf("Digite os numeros:\n");
	scanf("%d %d",&n1,&n2);
	if(n1!=n2){
		if(n1%2!=0 && n2%2!=0){
			printf("Os numeros sao coprimos\n");
		}
		else
			printf("Os numeros nao sao coprimo\n");
	}
	else
		printf("Os numeros nao sao coprimo\n");
	return 0;
}

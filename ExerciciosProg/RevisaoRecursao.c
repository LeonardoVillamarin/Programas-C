#include <stdio.h>

int somatorio(int n){
	int soma;
	if(n == 1){
		soma = 1;
	}
	else
		soma = somatorio(n-1)+n;
	return soma;
}

int fatorial(int n){
	int fat;
	if(n == 1)
		fat = 1;
	else
		fat = fatorial(n-1)*n;
	return fat;
}

int fibonacci(int n){
	int fibo;
	if(n == 0)
		fibo = 0;
	else if(n == 1)
		fibo = 1;
	else
		fibo = fibonacci(n-2)+fibonacci(n-1);
	return fibo;
}

int main(){
	int n, s, f, fibo;
	printf("Digite um numero:\n");
	scanf("%d", &n);
	s = somatorio(n);
	printf("Somatorio: %d\n", s);
	f = fatorial(n);
	printf("Fatorial: %d\n", f);
	fibo = fibonacci(n);
	printf("Fibonacci: %d\n", fibo);

	return 0;
}
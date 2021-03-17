#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int vetor[100];
sem_t semaforo;

void * remove_par(void *arg){
	int i,j;
	int *contador = (int *)arg;
	int teste = *contador;
	for(i=0; i<(*contador); i++){
		if(vetor[i]%2==0){
			for(j=i; j<(*contador); j++){
				sem_wait(&semaforo);
				vetor[j] = vetor[j+1];
				sem_post(&semaforo);
			}
			i--;
			sem_wait(&semaforo);
			*contador=*contador-1;
			sem_post(&semaforo);
				//for(j=0; j<(*contador); j++){
					//printf("%d ",vetor[j]);
				//}
			printf("%d\n",teste);
		}
	}
}

void * remove_impar(void *arg){
	int i,j;
	int *contador = (int *)arg;
	int teste = *contador;
	for(i=0; i<(*contador); i++){
		if(vetor[i]%2!=0){
			for(j=i; j<(*contador); j++){
				sem_wait(&semaforo);
				vetor[j] = vetor[j+1];
				sem_post(&semaforo);
			}
			i--;
			sem_wait(&semaforo);
			*contador=*contador-1;
			sem_post(&semaforo);
				/*for(j=0; j<(*contador); j++){
					//printf("%d ",vetor[j]);
				}*/
			printf("%d \n",teste);
		}
	}
}

int main(){
	int i,contador=100;
	pthread_t thread1,thread2;
	sem_init(&semaforo, 1, 1);
	for(i=0; i<contador; i++){
		vetor[i] = rand()%100;
	}
	for(i=0; i<contador; i++){
		printf("%d ",vetor[i]);
	}
		printf("\n\n");

	pthread_create(&thread1,NULL,remove_par,(void *)(&contador));
	pthread_create(&thread2,NULL,remove_impar,(void *)(&contador));
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("%d \n",contador);
	if(contador==0){
		printf("O Vetor esta vazio\n");
	}

	sem_destroy(&semaforo);
	return 0;

}
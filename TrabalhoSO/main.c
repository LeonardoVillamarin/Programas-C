#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>

void * funcao(void *arg){
    
    int *v;
    v = arg;
	//int numero_thread = *v;
	//numero_thread++;
  	int id_pthread_self = pthread_self();
    int id_gettid = syscall(SYS_gettid);
    printf("Eu sou a thread%d e meu id pthread_self é %u e meu id gettid é %u \n",*v, id_pthread_self, id_gettid);
}

int main(){
   	int numero_threads;
  	printf("Digite quantas threads serão criadas:\n");
   	scanf("%d",&numero_threads);
   	pthread_t thread[numero_threads];
   	int i,j;
   	for(i=0; i<numero_threads; i++){
        pthread_create(&thread[i], NULL, funcao, (void *)&i);
        //pthread_join(thread[i], NULL);
    }
    for(i=0; i<numero_threads; i++){
    	pthread_join(thread[i], NULL);
    	}
    	return 0;
}


typedef struct no {
    TElem elemento;
    No* prox;
}No;

typedef struct deque {
    int tamanho = 0;
    No *ini;
    No *fim;
}Deque;

void insereInicio(Deque *d, TElem elemento){
	if (d->tamanho == 0) {
        d->ini = (No*)malloc(sizeof(No));
        d->ini->elemento = elemento;
        d->fim = d->ini;
        d->tamanho++;
    }
    else {
    	Deque *aux = (No*)malloc(sizeof(No));
    	aux->elemento = elemento;
        aux->prox = d->ini; 
        d->ini = aux;
        d->tamanho++;
    }
}

void insereFim(Deque *d, TElem x){
	if (d->tamanho == 0) {
        d->ini = (No*)malloc(sizeof(No));
        d->ini->elemento = elemento;
        d->fim = d->ini;
        d->tamanho++;
    }
    else {
        d->fim->prox = (No*)malloc(sizeof(No));
        d->fim->prox->elemento = elemento;
        d->fim->prox->prox = NULL;
        d->fim = d->fim->prox;
        d->tamanho++;
    }
}



void removeInicio(Deque *d){
	TElem elemento;
    No *aux;
    
    if (d->tamanho == 0) 
        return 0;
    else {
        aux = d->ini;
        d->ini = d->ini->prox;
        free(aux);
        d->tamanho--;
    }
}

void removeFim(Deque *d){
	TElem elemento;
	No *aux;

	if (d->tamanho == 0)
		return 0;
	else{
		aux = d->fim;
		while (d->prox->prox != NULL)
			d->fim = d->prox;
		free(aux);
		d->tamanho--;
	}
}

TElem buscaInicio(Deque *q){
	TElem elemento;
	if(d->tamanho == 0)
		return 0
	elemento = d->ini->elemento;
	return elemento;
}

TElem buscaFim(Deque *q){
	TElem elemento;
	if(d->tamanho == 0)
		return 0
	elemento = d->fim->elemento;
	return elemento;
}








    


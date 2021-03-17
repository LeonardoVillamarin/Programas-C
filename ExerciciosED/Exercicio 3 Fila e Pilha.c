
void enfileira(Pilha p, Tipo elemento){
	p.empilha(elemento);
}

Tipo desinfileira(Pilha p, Pilha q){
	Tipo elemento;
	if(p.tamanho > 0){
		while(p.tamanho > 1)
			q.empilha(p.desempilha());
		elemento = p.desempilha();
		return elemento;
	}
	else{
		while(q.tamanho > 1)
			p.empilha(q.desempilha());
		elemento = q.desempilha();
		return elemento;
	}
}
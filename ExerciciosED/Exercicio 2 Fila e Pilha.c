

void empilha(Fila f, Tipo elemento){
	f.enfileira(elemento);
}

Tipo desempilha(Fila f, Fila g){
	Tipo elemento;
	if(f.tamanho > 0){
		while(f.tamanho > 1)
			g.enfileira(f.desenfileira());
		elemento = f.desenfileira();
		return elemento;
		}
	else{
		while(g.tamanho > 1)
			f.enfileira(g.desenfileira());
		elemento = g.desenfileira();
		return elemento;
	}
}
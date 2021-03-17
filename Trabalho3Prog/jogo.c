#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

Jogo criaJogo(Personagem p1, Personagem p2, int rodadas){
	Jogo j;
	j.rodadas = rodadas;
	j.p1 = p1;
	j.p2 = p2;
	j.p1.especial = 0;
	j.p2.especial = 0;
	j.p1.defesa_ligada = 0;
	j.p2.defesa_ligada = 0;
	return j;
}

int fimDeJogo(Jogo j){
	if (retornaVida(j.p1)<=0){
		return 1;
	}
	if (retornaVida(j.p2)<=0){
		return 2;	
	}
	if (retornaRodadas(j)<=0){
		return 3;
	}
	return 0;
}

int retornaRodadas(Jogo j){
	return j.rodadas;
}

void golpeEspecial(Jogo *j, int jogador){
	if(jogador==1){
		danoEspecial(&j->p1, &j->p2);
		(*j).rodadas--;
	}
	if(jogador==2){
		danoEspecial(&j->p2, &j->p1);
		(*j).rodadas--;
	}
	return;
}

void golpeSoco(Jogo *j, int jogador){
	if(jogador==1){
		danoSoco((*j).p1, &j->p2);
		incrementaEspecial(&j->p1);
		(*j).rodadas--;
	}
	if(jogador==2){
		danoSoco((*j).p2, &j->p1);
		incrementaEspecial(&j->p2);
		(*j).rodadas--;
	}
	return;
}

void golpeChute(Jogo *j, int jogador){
	if(jogador==1){
		danoChute((*j).p1, &j->p2);
		incrementaEspecial(&j->p1);
		(*j).rodadas--;
	}
	if(jogador==2){
		danoChute((*j).p2, &j->p1);
		incrementaEspecial(&j->p2);
		(*j).rodadas--;
	}
	return;
}

void golpeCombo(Jogo *j, int jogador){
	if(jogador==1){
		danoCombo((*j).p1, &j->p2);
		incrementaEspecial(&j->p1);
		(*j).rodadas--;
	}
	if(jogador==2){
		danoCombo((*j).p2, &j->p1);
		incrementaEspecial(&j->p2);
		(*j).rodadas--;
	}
	return;
}

void golpeDefesa(Jogo *j, int jogador){
	if(jogador == 1){
		posicaoDefesa(&j->p1);
		(*j).rodadas--;
	}
	if(jogador == 2){
		posicaoDefesa(&j->p2);
		(*j).rodadas--;
	}
	return;
}

void golpeVida(Jogo *j, int jogador){
	if(jogador == 1){
		recuperaVida(&j->p1);
		(*j).rodadas--;
	}
	if(jogador == 2){
		recuperaVida(&j->p2);
		(*j).rodadas--;
	}
	return;
}

void imprimeVencedor(Jogo j){
	char *nome;
	char *nome2;
	nome = (char *)malloc(101*sizeof(char));
	nome2 = (char *)malloc(101*sizeof(char));
	if(fimDeJogo(j)==1){
		retornaNome(j.p2, nome);
		printf("%s ganhou com %d de vida!!\n", nome, retornaVida(j.p2));
	}
	if(fimDeJogo(j)==2){
		retornaNome(j.p1, nome);
		printf("%s ganhou com %d de vida!!\n", nome, retornaVida(j.p1));	
	}
	if(fimDeJogo(j)==3){
		if(retornaVida(j.p1)>retornaVida(j.p2)){
			retornaNome(j.p1, nome);
			printf("O Tempo Acabou!!\n%s Ganhou com %d de vida!!\n", nome, retornaVida(j.p1));
		}
		if(retornaVida(j.p2)>retornaVida(j.p1)){
			retornaNome(j.p2, nome);
			printf("O Tempo Acabou!!\n%s Ganhou com %d de vida!!\n", nome, retornaVida(j.p2));
		}
		if(retornaVida(j.p1) == retornaVida(j.p2)){
			retornaNome(j.p1, nome);
			retornaNome(j.p2, nome2);
			printf("O Tempo Acabou!!\n%s e %s empataram com %d de vida!!\n", nome, nome2, retornaVida(j.p1));
		}
	}
	free(nome);
	free(nome2);	
	return;
}
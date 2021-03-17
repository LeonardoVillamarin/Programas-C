#include <stdio.h>
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
		if((*j).p1.especial==10){
			if((*j).p2.defesa_ligada==1){//Se a defesa estiver ligada
				(*j).p2.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
				(*j).p1.especial = 0;
				(*j).rodadas--;
			}	
			else{
				danoEspecial(&j->p1, &j->p2);//Se nao tiver ligada, da o dano do golpe
				(*j).p1.especial = 0;
				(*j).rodadas--;
			}
		}
		else
			(*j).rodadas--;
	}
	if(jogador==2){
		if((*j).p2.especial == 10){
			if((*j).p1.defesa_ligada==1){//Se a defesa estiver ligada
            	(*j).p1.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
				(*j).p2.especial = 0;
				(*j).rodadas--;
			}	
			else{
				danoEspecial(&j->p2, &j->p1);//Se nao tiver ligada, da o dano do golpe
				(*j).p2.especial = 0;
				(*j).rodadas--;
			}
		}
		else
			(*j).rodadas--;	
	}
	return;
}

void golpeSoco(Jogo *j, int jogador){
	if(jogador==1){
		if((*j).p2.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p2.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
		else{
			danoSoco(j->p1, &j->p2);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
	}
	if(jogador==2){
		if((*j).p1.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p1.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
		else{
			danoSoco(j->p2, &j->p1);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
	}
	return;
}

void golpeChute(Jogo *j, int jogador){
	if(jogador==1){
		if((*j).p2.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p2.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
		else{
			danoChute(j->p1, &j->p2);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
	}
	if(jogador==2){
		if((*j).p1.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p1.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
		else{
			danoChute(j->p2, &j->p1);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
	}
	return;
}

void golpeCombo(Jogo *j, int jogador){
	if(jogador==1){
		if((*j).p2.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p2.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
		else{
			danoCombo(j->p1, &j->p2);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p1);
			(*j).rodadas--;
		}
	}
	if(jogador==2){
		if((*j).p1.defesa_ligada==1){//Se a defesa estiver ligada
			(*j).p1.defesa_ligada=0;//Nao vai dar dano e vai desativar a defesa
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
		else{
			danoCombo(j->p2, &j->p1);//Se nao tiver ligada, da o dano do golpe
			incrementaEspecial(&j->p2);
			(*j).rodadas--;
		}
	}
	return;
}

void golpeDefesa(Jogo *j, int jogador){
	if(jogador == 1){
		posicaoDefesa(&j->p1);//Ativa a defesa
		(*j).rodadas--;
	}
	if(jogador == 2){
		posicaoDefesa(&j->p2);//Ativa a defesa
		(*j).rodadas--;
	}
	return;
}

void golpeVida(Jogo *j, int jogador){
	if(jogador == 1){
		recuperaVida(&j->p1);//Recupera a vida
		(*j).rodadas--;
	}
	if(jogador == 2){
		recuperaVida(&j->p2);//Recupera a vida
		(*j).rodadas--;
	}
	return;
}

void imprimeVencedor(Jogo j){
	char nome[101];
	char nome2[101];
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
	return;
}
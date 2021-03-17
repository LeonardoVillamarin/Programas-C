#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagem.h"

Personagem criaPersonagem(char *nome, int hp, int ataque, int defesa){
	Personagem p;
	p.nome = (char *)malloc(101*sizeof(char));
	strcpy(p.nome, nome);
	p.hp = hp;
	p.hp_atual = hp;
	p.ataque = ataque;
	p.defesa = defesa;
	return p;	
}

void incrementaEspecial(Personagem *p){
	if((*p).especial<10){
		(*p).especial++;
	}
	return;
}

void danoEspecial(Personagem *pa, Personagem *pd){
	int dano = ((float)ESPECIAL*10.0/2.0)*((float)(*pa).ataque/(float)(*pd).defesa)+1.0;
	if((*pa).especial==10){
		if((*pd).defesa_ligada==0){
			if((*pa).defesa_ligada==1){
				(*pd).hp_atual -= dano;
				(*pd).hp_atual++;
				(*pa).especial = 0;
			}
			else{
				(*pd).hp_atual -= dano;
				(*pa).especial = 0;
			}
		}
		else{
			(*pd).defesa_ligada=0;
			(*pa).especial = 0;
		}
	}
	return;	
}

void danoSoco(Personagem pa, Personagem *pd){
	int dano = ((float)SOCO*10.0/2.0)*((float)pa.ataque/(float)(*pd).defesa)+1.0;
	if((*pd).defesa_ligada==0){
		if(pa.defesa_ligada==1){
			(*pd).hp_atual -= dano;
			(*pd).hp_atual++;
		}
		else
			(*pd).hp_atual -= dano;
	}
	else
		(*pd).defesa_ligada = 0;
	return;
}

void danoChute(Personagem pa, Personagem *pd){
	int dano = ((float)CHUTE*10.0/2.0)*((float)pa.ataque/(float)(*pd).defesa)+1.0;
	if((*pd).defesa_ligada==0){
		if(pa.defesa_ligada==1){
			(*pd).hp_atual -= dano;
			(*pd).hp_atual++;
		}
		else
			(*pd).hp_atual -= dano;
	}
	else
		(*pd).defesa_ligada = 0;	
	return;
}

void danoCombo(Personagem pa, Personagem *pd){
	int dano = ((float)COMBO*10.0/2.0)*((float)pa.ataque/(float)(*pd).defesa)+1.0;
	if((*pd).defesa_ligada==0){
		if(pa.defesa_ligada==1){
			(*pd).hp_atual -= dano;
			(*pd).hp_atual++;
		}
		else
			(*pd).hp_atual -= dano;
	}
	else
		(*pd).defesa_ligada = 0;
	return;
}

void posicaoDefesa(Personagem *p){
	if((*p).defesa_ligada==0){
		(*p).defesa_ligada=1;
	}
	return;
}

void recuperaVida(Personagem *p){
	(*p).hp_atual = (*p).hp;
	return;
}

void retornaNome(Personagem p, char *nome){
	strcpy(nome, p.nome);
	return;
}

int retornaVida(Personagem p){
	return p.hp_atual;
}
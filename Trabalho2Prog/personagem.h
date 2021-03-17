#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <stdio.h>
#include <string.h>

#define SOCO 1
#define CHUTE 2
#define COMBO 3
#define ESPECIAL 5

typedef struct personagem {
	char nome[101];
	int hp;
	int hp_atual;
	int defesa_ligada;
	unsigned int especial;
	unsigned int ataque;
	unsigned int defesa;
} Personagem;

// cria um novo personagem
Personagem criaPersonagem(char nome[], int hp, int ataque, int defesa);

// incrementa o valor do especial do personagem
void incrementaEspecial(Personagem *p);

// faz o personagem atacante pa dar o dano de um especial no personagem de defesa pd
void danoEspecial(Personagem *pa, Personagem *pd);

// faz o personagem atacante pa dar o dano de um soco no personagem pd
void danoSoco(Personagem pa, Personagem *pd);

// faz o personagem atacante pa dar o dano de um chute no personagem pd
void danoChute(Personagem pa, Personagem *pd);

// faz o personagem atacante pa dar o dano de um combo no personagem pd
void danoCombo(Personagem pa, Personagem *pd);

// faz o personagem atacante entrar em posicao de defesa
void posicaoDefesa(Personagem *p);

// recupera a vida do personagem
void recuperaVida(Personagem *p);

// retorna o nome do personagem
void retornaNome(Personagem p, char nome[]);

// retorna a vida do personagem
int retornaVida(Personagem p);

#endif
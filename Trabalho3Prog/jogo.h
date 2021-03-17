#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagem.h"

typedef struct jogo {
	Personagem p1;
	Personagem p2;
	int rodadas;
} Jogo;

// começa um novo jogo
Jogo criaJogo(Personagem p1, Personagem p2, int rodadas);

// condicao que indica que um jogo terminou: 
// retorna 0 se o jogo nao acabou
// retorna 1 se o personagem do jogador 1 morreu
// retorna 2 se o personagem do jogador 2 morreu
// retorna 3 se o tempo acabou
int fimDeJogo(Jogo j);

// retorna o número de rodadas restantes
int retornaRodadas(Jogo j);

// o jogador da um golpe especial
void golpeEspecial(Jogo *j, int jogador);

// o jogador da um soco
void golpeSoco(Jogo *j, int jogador);

// o jogador da um chute
void golpeChute(Jogo *j, int jogador);

// o jogador da um combo
void golpeCombo(Jogo *j, int jogador);

// o jogador defende
void golpeDefesa(Jogo *j, int jogador);

// o jogador recupera vida ao maximo possivel
void golpeVida(Jogo *j, int jogador);

// imprime na tela qual personagem ganhou o jogo
void imprimeVencedor(Jogo j);

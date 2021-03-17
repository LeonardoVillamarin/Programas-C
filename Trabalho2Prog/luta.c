#include <stdio.h>
#include "jogo.h"

int main(){
	Personagem p1, p2, p3, p4, p5, p6;
	Jogo j;
	char nome[101];
	char golpe;
	int hp, ataque, defesa, jogador, rodadas, player1, player2;
	printf("Digite os dados do personagem 1:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p1 = criaPersonagem(nome, hp, ataque, defesa);
	printf("Digite os dados do personagem 2:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p2 = criaPersonagem(nome, hp, ataque, defesa);
	printf("Digite os dados do personagem 3:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p3 = criaPersonagem(nome, hp, ataque, defesa);
	printf("Digite os dados do personagem 4:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p4 = criaPersonagem(nome, hp, ataque, defesa);
	printf("Digite os dados do personagem 5:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p5 = criaPersonagem(nome, hp, ataque, defesa);
	printf("Digite os dados do personagem 6:\n");
	scanf("%s", nome);
	scanf("%d %d %d", &hp, &ataque, &defesa);
	p6 = criaPersonagem(nome, hp, ataque, defesa);
	
	scanf("%d %d %d", &player1, &player2, &rodadas);
	while(player1 != 0 && player2 != 0 && rodadas != 0){
		if(player1 == 1){
			if(player2 == 1)
				j = criaJogo(p1, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p1, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p1, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p1, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p1, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p1, p6, rodadas);
		}
		if(player1 == 2){
			if(player2 == 1)
				j = criaJogo(p2, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p2, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p2, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p2, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p2, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p2, p6, rodadas);
		}
		if(player1 == 3){
			if(player2 == 1)
				j = criaJogo(p3, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p3, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p3, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p3, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p3, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p3, p6, rodadas);
		}
		if(player1 == 4){
			if(player2 == 1)
				j = criaJogo(p4, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p4, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p4, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p4, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p4, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p4, p6, rodadas);
		}		
		if(player1 == 5){
			if(player2 == 1)
				j = criaJogo(p5, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p5, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p5, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p5, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p5, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p5, p6, rodadas);
		}
		if(player1 == 6){
			if(player2 == 1)
				j = criaJogo(p6, p1, rodadas);
			if(player2 == 2)
				j = criaJogo(p6, p2, rodadas);
			if(player2 == 3)
				j = criaJogo(p6, p3, rodadas);
			if(player2 == 4)
				j = criaJogo(p6, p4, rodadas);
			if(player2 == 5)
				j = criaJogo(p6, p5, rodadas);
			if(player2 == 6)
				j = criaJogo(p6, p6, rodadas);
		}
		
		while(fimDeJogo(j)==0){
			scanf("%c %d", &golpe, &jogador); 
			if(golpe == 'E'){ 
				golpeEspecial(&j, jogador);
			}
			if(golpe == 'S'){
				golpeSoco(&j, jogador);
			}
			if(golpe == 'C'){
				golpeChute(&j, jogador);
			}
			if(golpe == 'O'){
				golpeCombo(&j, jogador);
			}
			if(golpe == 'D'){
				golpeDefesa(&j, jogador);
			}
			if(golpe == 'V'){
				golpeVida(&j, jogador);
			}
		}
		if(fimDeJogo(j) != 0){
			imprimeVencedor(j);
			scanf("%d %d %d", &player1, &player2, &rodadas);
		}
	}
	return 0;
}




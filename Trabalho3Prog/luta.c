#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
	Personagem p1, p2;
	Jogo j;
	char golpe;
	char *nome = (char *)malloc(101*sizeof(char));
	int hp, ataque, defesa, jogador, rodadas, player1, player2, total_personagens;
	scanf("%d",&total_personagens);
	Personagem *personagens = (Personagem *)malloc(total_personagens*sizeof(Personagem)); //Vetor que armazena os personagens
	
	for(int i=0; i<total_personagens; i++){
		printf("Digite os dados do personagem %d:\n",i+1);
		scanf("%s", nome);
		scanf("%d %d %d", &hp, &ataque, &defesa);
	 	*(personagens+i) = criaPersonagem(nome, hp, ataque, defesa);
	}
	
	scanf("%d %d %d", &player1, &player2, &rodadas);
	while(player1 != 0 && player2 != 0 && rodadas != 0){
		j = criaJogo(*(personagens+player1-1) , *(personagens+player2-1), rodadas);
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
	free(nome);
	free(personagens);
	return 0;
}
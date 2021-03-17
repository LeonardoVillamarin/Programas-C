#include <stdio.h>

typedef struct personagem{
    	char nome[101];
    	int vida;
    	int ataque;
    	int defesa;
	    int soco; //Recebe o valor do dano calculado do soco
    	int chute; //Recebe o valor do dano calculado do chute
    	int especial; //Recebe o valor do dano calculado do especial
    	int contador_especial;
}Personagem;

typedef struct jogo{
    	Personagem perso1,perso2;
    	int rodadas; //Total de rodadas da partida, incrementa 1 a cada rodada jogada
    	char golpe; //Recebe a entrada de qual ataque será efetuado na rodada
    	int jogador; //Recebe a entrada de qual jogador atacará na rodada
}Jogo;

int main(){
    	Jogo game;
    	printf("Digite os dados do Personagem 1:\n");
    	scanf("%s\n",game.perso1.nome);
    	scanf("%d %d %d\n",&game.perso1.vida, &game.perso1.ataque, &game.perso1.defesa);
    	while(game.perso1.vida<0 || game.perso1.ataque<0 || game.perso1.defesa<0){ //Enquanto o usuário não digitar um valor maior que 0 o programa não continua
        scanf("%d %d %d\n",&game.perso1.vida, &game.perso1.ataque, &game.perso1.defesa);
    	}
    	printf("Digite os dados do Personagem 2:\n");
    	scanf("%s\n",game.perso2.nome);
    	scanf("%d %d %d\n",&game.perso2.vida, &game.perso2.ataque, &game.perso2.defesa);
    	while(game.perso2.vida<0 || game.perso2.ataque<0 || game.perso2.defesa<0){ //Enquanto o usuário não digitar um valor maior que 0 o programa não continua
     	scanf("%d %d %d\n",&game.perso2.vida, &game.perso2.ataque, &game.perso2.defesa);
    	}

    	game.perso1.soco=(1.0*10.0/2.0)*((float)game.perso1.ataque/(float)game.perso2.defesa)+1.0;  //Calcula o dano do soco do jogador 1 em float e armazena na struct em int
    	game.perso1.chute=(2.0*10.0/2.0)*((float)game.perso1.ataque/(float)game.perso2.defesa)+1.0;  //Calcula o dano do chute do jogador 1 em float e armazena na struct em int
    	game.perso1.especial=(5.0*10.0/2.0)*((float)game.perso1.ataque/(float)game.perso2.defesa)+1.0;  //Calcula o dano do especial do jogador 1 em float e armazena na struct em int

	    game.perso2.soco=(1.0*10.0/2.0)*((float)game.perso2.ataque/(float)game.perso1.defesa)+1.0;  //Calcula o dano do soco do jogador 2 em float e armazena na struct em int
    	game.perso2.chute=(2.0*10.0/2.0)*((float)(game.perso2.ataque)/(float)game.perso1.defesa)+1.0;  //Calcula o dano do chute do jogador 2 em float e armazena na struct em int
    	game.perso2.especial=(5.0*10.0/2.0)*((float)game.perso2.ataque/(float)game.perso1.defesa)+1.0;  //Calcula o dano do especial do jogador 2 em float e armazena na struct em int

    	game.rodadas=0;
    	game.perso1.contador_especial=0; //Contador de especial do jogador 1 recebe 0
    	game.perso2.contador_especial=0; //Contador de especial do jogador 2 recebe 0

    	while ((game.perso1.vida>0.0) && (game.perso2.vida>0.0) && (game.rodadas<=50)){
        	scanf("%c %i\n", &game.golpe, &game.jogador);
        	if(game.golpe=='S'){
            	if(game.jogador==1){
                	game.perso2.vida = game.perso2.vida - game.perso1.soco; //Diminui a vida do jogador 2 de acordo com o dano calculado
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso1.contador_especial<10){ //Confere se o contador do especial já chegou a 10
                    	game.perso1.contador_especial++; //Se não chegou a 10, incrementa 1
                	}
            	}
            	if(game.jogador==2){
                	game.perso1.vida = game.perso1.vida - game.perso2.soco; //Diminui a vida do jogador 1 de acordo com o dano calculado
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso2.contador_especial<10){ //Confere se o contador do especial já chegou a 10
                    	game.perso2.contador_especial++; //Se não chegou a 10, incrementa 1
                	}
            	}
        	}
        	if(game.golpe=='C'){
            	if(game.jogador==1){
                	game.perso2.vida = game.perso2.vida - game.perso1.chute; //Diminui a vida do jogador 2 de acordo com o dano calculado
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso1.contador_especial<10){ //Confere se o contador do especial já chegou a 10
                    	game.perso1.contador_especial++; //Se não chegou a 10, incrementa 1
                	}
            	}
            	if(game.jogador==2){
                	game.perso1.vida = game.perso1.vida - game.perso1.chute; //Diminui a vida do jogador 1 de acordo com o dano calculado
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso2.contador_especial<10){ //Confere se o contador do especial já chegou a 10
                    	game.perso2.contador_especial++; //Se não chegou a 10, incrementa 1
                	}
            	}
        	}
        	if (game.golpe=='E'){
            	if(game.jogador==1){
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso1.contador_especial==10){ //Confere se o contador do especial já chegou a 10
                    	game.perso2.vida = game.perso2.vida - game.perso1.especial; //Diminui a vida do jogador 2 de acordo com o dano calculado
                    	game.perso1.contador_especial=0; //Reseta o contador do especial
                	}
            	}
            	if(game.jogador==2){
                	game.rodadas++; //Incrementa o número de rodadas
                	if(game.perso2.contador_especial==10){  //Confere se o contador do especial já chegou a 10
                    	game.perso1.vida = game.perso1.vida - game.perso2.especial; //Diminui a vida do jogador 1 de acordo com o dano calculado
                    	game.perso2.contador_especial=0; //Reseta o contador do especial
                	}
            	}
        	}
    	}

    	if(game.perso1.vida<=0.0){
        	printf("%s ganhou!!\n", game.perso2.nome);
    	}
    	if(game.perso2.vida<=0.0){
        	printf("%s ganhou!!\n", game.perso1.nome);
    	}
    	if(game.rodadas>=50){
        	printf("O tempo acabou\n");
        	if(game.perso1.vida>game.perso2.vida){
            	printf("%s ganhou!!\n", game.perso1.nome);
        	}
        	if(game.perso2.vida>game.perso1.vida){
            	printf("%s ganhou!!\n", game.perso2.nome);
        	}
        	if(game.perso1.vida==game.perso2.vida){
            	printf("Empate!!\n");
        	}
    	}
    	return 0;
}

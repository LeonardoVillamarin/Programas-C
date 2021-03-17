#include <stdio.h>
// valores dos golpes
#define soco 1.0
#define chute 2.0
#define especial 5.0
#define MAX 100
 

int damage (float p, float a, float d){ // equacao de dano causado
 
  float x,y,z;
  x = p * 5;
  y = (float)a/(float)d;
  z = x * y;
  z++;
  return (int)z;
 
}

typedef struct jogo{
  
  int game_over;// quem morreu
  float s,c,e; // golpes
  char golpe; // golpe utilizado  
  float dano_total; // dano total causado 
  int const_esp; //contador para o especial
  int rodada; // quem ira dar o dano
  int time_out;
 
}Jogo;
 
typedef struct personagem{ //dados dos personagens
 
  char nome[MAX]; //numero maximo de caracteres do nome
  int vida; //dados dos personagens
  int ataque;
  int defesa;
  Jogo x; //as variaveis do jogo junto aos personagens
 
}Personagem;
 
 
 
int main(){
 
  Personagem p1,p2; //criando 2 personagens
     
  Jogo x; // criando todas os variaveis para jogar
         
  p1.x.const_esp = 0; //contador para o especial do p1 e p2
  p2.x.const_esp = 0;
  
  x.time_out = 0;  //contador de para limitar numero de rodadas
  

  x.game_over = -1; // caso este contador mude um jogador estara morto   
     
  x.s = soco; // passando os valorwes dos golpes para as variaveis 
  x.c = chute;
  x.e = especial;
     
  printf("Digite os dados do Personagem 1:\n"); // imformacoes do p1
  scanf("%s\n",p1.nome);  
  scanf("%d %d %d",&p1.vida,&p1.ataque,&p1.defesa);
 
  printf("Digite os dados do Personagem 2:\n"); // imformacoes do p2
  scanf("%s\n",p2.nome);  
  scanf("%d %d %d",&p2.vida,&p2.ataque,&p2.defesa);
  

 
  while (x.game_over == -1){ //se a variavel nao for trocada a luta continua
    if(x.time_out<50){ //condiçao para parar depois de 50 rodadas, tentei por a condiçao com while mais deu um erro...
      scanf("%c",&x.golpe);// le qual golpe usou e quem vai atacar
      scanf("%d",&x.rodada); 
      
      switch (x.golpe){ //
        case 'S':   
          if (x.rodada==1){ // caso escolha que o p1 ataque           
            x.dano_total = damage(x.s,p1.ataque,p2.defesa); // passando os valores para a funcao        
            p2 .vida = p2.vida - x.dano_total; //reduz a vida do p2         
            p1.x.const_esp = p1.x.const_esp + 1; //contador de especial        
            x.time_out++; // a varivel de limite de rodade é incrementada 
            if(p2.vida <=0.0){ // verifica se ele morreu 
              x.game_over = 2; // assim vou saber q o p2 morrreu    
            }
            break;
          }
          else{            
            x.dano_total = damage(x.s,p2.ataque, p1.defesa); //caso seje o jogador 2 atacando
            p1.vida = p1.vida - x.dano_total;
            p2.x.const_esp = p2.x.const_esp + 1;
            x.time_out++;
            if (p1.vida <=0.0){
              x.game_over = 1;
            }
            break;
          }
      
          case 'C':
          if (x.rodada==1){       
            x.dano_total = damage(x.c, p1.ataque, p2.defesa);        
            p2.vida = p2.vida - x.dano_total;         
            p1.x.const_esp = p1.x.const_esp + 1;          
            x.time_out++;
            if (p2.vida<=0){
              x.game_over = 2;
            }           
          }
          else{
            x.dano_total = damage(x.c, p2.ataque, p1.defesa);
            p1.vida = p1.vida - x.dano_total;
            p2.x.const_esp = p2.x.const_esp + 1;
            x.time_out++;
            if(p1.vida<=0){
              x.game_over = 1; 
            }
          }
          break;
          case 'E':
          if(x.rodada==1){ // caso jogador 1 usar o especial 
            if(p1.x.const_esp <10){
              p1.x.const_esp = 0; //usar o especial sem ter 10 pontos... o contador e zerado e começa outra rodada
              x.time_out++; 
              break;
            }
          }      
          else{
            x.dano_total = damage(x.e, p1.ataque, p2.defesa); // se jogador 1 usar especial e tiver os 10 pontos
            p2.vida = p2.vida - x.dano_total;
            p1.x.const_esp = 0; //depois de usar especial o contador zerado
            x.time_out++;
            if (p2.vida<=0){
              x.game_over = 2;
              break;
            }              
          }    
          if(x.rodada==2){ // caso o jogador 2 use o especial sem ter os 10 pontos
            if (p2.x.const_esp<10){
              p2.x.const_esp = 0;
              x.time_out++;
              break;
            }
          }
          else{ // caso ja tenhs os 10 pontos
            x.dano_total = damage(x.e, p2.ataque, p1.defesa);
            p1.vida = p1.vida - x.dano_total;
            p2.x.const_esp = 0;
            x.time_out++;
            if (p1.vida<=0){
              x.game_over = 1;
              break;
            }
          }
        }
      } 
    }
  
  if (x.time_out<50){ //se o limite de rodada nao foi alcançado ele verifica quem ganhou
    if(x.game_over==2){
    printf("%s ganhou!",p1.nome); // p1 ganhou
  }
    if(x.game_over==1){
      printf("%s ganhou!",p2.nome); // p2 ganhou
    }
  }
  else{
    if(p1.vida<p2.vida){ // caso o limite da rodada foi alcançado e o p1 tiver menos vida o p2 ganha
      printf("o tempo acabou!\n");
      printf("%s ganhou",p2.nome); 
    }
    if(p2.vida<p1.vida){ // p2 ganhou
      printf("o tempo acabou!\n");
      printf("%s ganhou", p1.nome);  
    }
    else{ // caso aja um empate
      printf("houve um empate entre %s e %s",p1.nome,p2.nome);
    }
  }
    return 0;
}



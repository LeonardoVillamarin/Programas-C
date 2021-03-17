all: printy

printy:	luta.o	jogo.o	personagem.o
	gcc -o	printy	luta.o	jogo.o	personagem.o

luta.o: luta.c jogo.h personagem.h
	gcc -o	luta.o	luta.c -c -W

luta.o: luta.c jogo.h personagem.h
	gcc -o	luta.o	luta.c -c -W 

personagem.o: personagem.c personagem.h
	gcc -o	personagem.o	personagem.c -c -W 

clean:
	rm -rf *.o *~ printy
CC=gcc
OPTS=-Wall -g
PROG=main

all: ${PROG}

${PROG}: main.o joueur.o objet.o carte.o matrice.o
	${CC} main.o joueur.o objet.o carte.o matrice.o ${OPTS} -o ${PROG} -pthread

main.o: main.c main.h objet.h joueur.h carte.h
	${CC} -c main.c ${OPTS} -o main.o

objet.o: objet.c objet.h
	${CC} -c objet.c ${OPTS} -o objet.o

joueur.o: joueur.c joueur.h objet.h
	${CC} -c joueur.c ${OPTS} -o joueur.o

carte.o: carte.c carte.h matrice.h
	${CC} -c carte.c ${OPTS} -o carte.o

matrice.o: matrice.c matrice.h case.h joueur.h
	${CC} -c matrice.c ${OPTS} -o matrice.o

clean:
	rm -f *.o

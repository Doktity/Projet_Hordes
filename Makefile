CC=gcc
OPTS=-Wall -g
PROG=main

all: ${PROG}

${PROG}: main.o joueur.o objet.o
	${CC} main.o joueur.o objet.o ${OPTS} -o ${PROG}

main.o: main.c main.h objet.h joueur.h
	${CC} -c main.c ${OPTS} -o main.o

objet.o: objet.c objet.h
	${CC} -c objet.c ${OPTS} -o objet.o

joueur.o: joueur.c joueur.h objet.h
	${CC} -c joueur.c ${OPTS} -o joueur.o

clean:
	rm -f *.o

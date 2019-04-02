CC=gcc
OPTS=-Wall -g -lm -pthread
PROG=main

all: ${PROG}

${PROG}: main.o joueur.o objet.o carte.o matrice.o action.o banque.o maison.o puit.o liste_joueur.o atelier.o
	${CC} $^ ${OPTS} -o ${PROG}

%.o : %.c %.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf ${PROG}

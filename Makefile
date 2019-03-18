CC=gcc
OPTS=-Wall -g
PROG=main

all: ${PROG}

${PROG}: main.o joueur.o objet.o carte.o matrice.o action.o banque.o maison.o puit.o
	${CC} $^ ${OPTS} -o ${PROG} -pthread
	
%.o : %.c %.h

clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf ${PROG}

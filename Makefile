CC=gcc
OPTS=-Wall -g -lm -pthread

all: serveur client

serveur: serveur.o joueur.o objet.o carte.o matrice.o action.o banque.o maison.o puit.o liste_joueur.o
	${CC} $^ ${OPTS} -o serveur

client: client.o joueur.o objet.o carte.o matrice.o action.o banque.o maison.o puit.o liste_joueur.o
	${CC} $^ ${OPTS} -o client

%.o : %.c %.h

clean:
	rm -rf *.o

mrproper: clean
	rm -rf ${PROG}

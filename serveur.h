#ifndef _SERVEUR_H_
#define _SERVEUR_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#include "joueur.h"
#include "objet.h"
#include "carte.h"
#include "banque.h"
#include "maison.h"
#include "puit.h"
#include "liste_joueur.h"


#define DIX 6
#define NB_ZOMBIE_MIN 10
#define NB_ZOMBIE_MAX 250
#define TAILLE_NOM 100


typedef struct {
  int nb_tour;
  time_t temps;
}tour_t;

char buffer[512];

void fin(int sig);
int hostname_to_ip(char * hostname , char* ip);
void view_ip();
int attaque(int nb_tour, int nb_joueur, int puissance);

#endif

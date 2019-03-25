#ifndef _ACTION_H_
#define _ACTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "joueur.h"
#include "objet.h"
#include "carte.h"


void deposer_objet(liste_objet_t * l, joueur_t * joueur);

void prendre_objet (liste_objet_t * l, joueur_t * joueur);

void utiliser_objet(joueur_t * joueur);

int nb_aleatoire(int ecart);

#endif


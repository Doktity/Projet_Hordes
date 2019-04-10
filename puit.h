#ifndef _PUIT_H_
#define _PUIT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "joueur.h"
#include "objet.h"

void puit(int choix, int * ration, joueur_t * joueur, liste_objet_t * liste);

void prendre_eau(int * ration, joueur_t * joueur, liste_objet_t * liste);

void ajouter_eau(int * ration, joueur_t * joueur, liste_objet_t * liste);

#endif

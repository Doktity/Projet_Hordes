#ifndef _PUIT_H_
#define _PUIT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "joueur.h"
#include "objet.h"

void puit(int * ration, joueur_t * joueur);

void prendre_eau(int * ration, joueur_t * joueur);

void ajouter_eau(int * ration, joueur_t * joueur);

#endif

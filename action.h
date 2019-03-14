#ifndef _ACTION_H_
#define _ACTION_H_

#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include "objet.h"
#include "carte.h"


void dehors(int posx, int posy, joueur_t * joueur,t_mat map);
void deposer_objet(liste_objet_t * l, joueur_t * joueur);
void prendre_objet (liste_objet_t * l, joueur_t * joueur);

#endif

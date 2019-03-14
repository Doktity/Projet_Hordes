#ifndef _CARTE_H_
#define _CARTE_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "boite_outil.h"
#include "matrice.h"


#define T  13//taille des côtés de la carte

t_mat * creer_carte();

void afficher_carte(t_mat * map);

t_mat * calculer_pos_zombie(t_mat * map, int nb_jour);

void action(int posx, int posy, joueur_t joueur,t_mat map);

#endif

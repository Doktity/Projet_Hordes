#ifndef _CARTE_H_
#define _CARTE_H_

#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"

#define T  13//taille des côtés de la carte

t_mat * creer_carte();

void afficher_carte(t_mat * map);

#endif

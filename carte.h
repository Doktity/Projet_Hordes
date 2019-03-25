#ifndef _CARTE_H_
#define _CARTE_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "action.h"
#include "matrice.h"


#define T  13//taille des côtés de la carte

t_mat * creer_carte();

void afficher_carte(t_mat * map);

int calculer_pos_zombie(t_mat * map, int nb_jour, int nb_zombie_hier);

void action_carte(joueur_t * joueur,t_mat * map);

static void gauche(joueur_t * joueur,t_mat * map);
static void droite(joueur_t * joueur,t_mat * map);
static void haut(joueur_t * joueur,t_mat * map);
static void bas(joueur_t * joueur,t_mat * map);

static void fouiller(joueur_t * joueur,t_mat * map);
static void attaquer(joueur_t * joueur,t_mat * map);
static void ramasser(joueur_t * joueur,t_mat * map);
#endif

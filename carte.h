#ifndef _CARTE_H_
#define _CARTE_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "matrice.h"
#include "action.h"


#define T  13//taille des côtés de la carte
#define NB_OBJET 14//nombre d'objet créer changer pour que ça soit dans le main ou par la liste d'objet, nombre définis par younes

t_mat * creer_carte();

void afficher_carte(t_mat * map);

int tour_de_jeu(t_mat * map, int nb_jour, int nb_zombie_hier);

void action_carte(joueur_t * joueur, t_mat * map,liste_objet_t * liste);

static void gauche(joueur_t * joueur, t_mat * map);
static void droite(joueur_t * joueur, t_mat * map);
static void haut(joueur_t * joueur, t_mat * map);
static void bas(joueur_t * joueur, t_mat * map);

static void fouiller(joueur_t * joueur,t_mat * map, liste_objet_t * liste);
static void attaquer(joueur_t * joueur, t_mat * map);
static void ramasser(joueur_t * joueur, t_mat * map);
static void poser(joueur_t * joueur,t_mat * map);
static void utiliser(joueur_t * joueur);
static void sortir(joueur_t * joueur,int * choix);
#endif

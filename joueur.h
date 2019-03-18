#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include <stdio.h>
#include <stdlib.h>

#include "objet.h"

#define TAILLE_INVENTAIRE 4
#define NB_STATUT 7

typedef struct joueur_s{
  char * nom;
  int pa;
  objet_t inventaire[TAILLE_INVENTAIRE];
  int statut[NB_STATUT];
  int maison;
} joueur_t;

joueur_t * Creer_Joueur(char * nom, int pa, objet_t inventaire[TAILLE_INVENTAIRE], int statut[NB_STATUT]); // Renvoie le joueur_t du joueur qu'on a créer.

void Supprimer_Joueur(joueur_t * joueur); // Supprime le joueur.

int Est_Clair(joueur_t * joueur); // Renvoie 1 si le joueur est clair, 0 sinon.

int Est_Soif(joueur_t * joueur); // Renvoie 1 si le joueur est assoifé, 0 sinon.

int Est_Fatigue(joueur_t * joueur); // Renvoie 1 si le joueur est fatigué, 0 sinon.

int Est_Blessure(joueur_t * joueur); // Renvoie 1 si le joueur est blessé, 0 sinon.

int Est_Drogue(joueur_t * joueur); // Renvoie 1 si le joueur est drogué, 0 sinon.

int Est_Rassasie(joueur_t * joueur); // Renvoie 1 si le joueur est rassasié, 0 sinon.

int Est_Immunise(joueur_t * joueur); // Renvoie 1 si le joueur est immunisé, 0 sinon.

void Afficher_inventaire(joueur_t * joueur); // Affiche l'inventaire du joueur.

void Trier_inventaire(joueur_t * joueur); // Trie l'inventaire du joueur.

#endif

#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include <stdio.h>
#include <stdlib.h>

#include "objet.h"

#define TAILLE_INVENTAIRE 4
#define NB_STATUT 7

typedef enum{
  etat_clair = 0,
  etat_soif,
  etat_fatigue,
  etat_blesse,
  etat_drogue,
  etat_rassasie,
  etat_immunise
}joueur_nb_etat;

typedef struct joueur_s{
  char * nom;
  int pa;
  objet_t * inventaire[TAILLE_INVENTAIRE];
  int statut[NB_STATUT];
  int maison;
  liste_objet_t * coffre;
  int posx;
  int posy;
} joueur_t;

joueur_t * creer_joueur(char * nom); // renvoie le joueur_t du joueur qu'on a créer.

void supprimer_joueur(joueur_t * joueur); // supprime le joueur.

int est_clair(joueur_t * joueur); // renvoie 1 si le joueur est clair, 0 sinon.

int est_soif(joueur_t * joueur); // renvoie 1 si le joueur est assoifé, 0 sinon.

int est_fatigue(joueur_t * joueur); // renvoie 1 si le joueur est fatigué, 0 sinon.

int est_blesse(joueur_t * joueur); // renvoie 1 si le joueur est blessé, 0 sinon.

int est_drogue(joueur_t * joueur); // renvoie 1 si le joueur est drogué, 0 sinon.

int est_rassasie(joueur_t * joueur); // renvoie 1 si le joueur est rassasié, 0 sinon.

int est_immunise(joueur_t * joueur); // renvoie 1 si le joueur est immunisé, 0 sinon.

void afficher_inventaire(joueur_t * joueur); // affiche l'inventaire du joueur.

void trier_inventaire(joueur_t * joueur); // trie l'inventaire du joueur.

int inventaire_vide(joueur_t * joueur);

#endif

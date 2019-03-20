#ifndef _LISTE_JOUEUR_H_
#define _LISTE_JOUEUR_H_

#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

typedef struct elt_joueur_s{
	joueur_t * valeur;
  struct elt_joueur_s * pred;
  struct elt_joueur_s * succ;
}elt_joueur_t;

elt_joueur_t * drapeau;
elt_joueur_t * ec;

void joueur_init_liste(void);

int joueur_liste_vide(void);

int joueur_hors_liste(void);

void joueur_en_tete(void);

void joueur_en_queue(void);

void joueur_suivant(void);

void joueur_precedent(void);

void joueur_valeur_elt(joueur_t ** j);

void joueur_modif_elt(joueur_t * j);

void joueur_oter_elt(void);

void joueur_ajout_droit(joueur_t * j);

void joueur_ajout_gauche(joueur_t * j);

void joueur_afficher_liste(void);

#endif

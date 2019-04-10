#ifndef _BANQUE_H_
#define _BANQUE_H_

#include "action.h"

typedef struct banque_s{
  liste_objet_t * nourriture;
  liste_objet_t * drogue;
  liste_objet_t * arme;
  liste_objet_t *obj_construct;
}banque_t;


void banque(int choix, banque_t *,joueur_t*);

void affiche_banque(banque_t *);

void ajouter_objet_banque(banque_t *,joueur_t *);

void retirer_objet_banque(banque_t *,joueur_t *);

void init_banque(banque_t *);

#endif

#ifndef _CASE_H_
#define _CASE_H_

#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include "objet.h"

typedef enum{
      non_explore,
      explore_neutre,
      explore_zombie,
      ville
}etat_case;

typedef enum{
      non_fouillee,
      fouillee
}est_fouillee;

typedef struct {
      etat_case etat;
      est_fouillee fouille;
      objet_t ** liste_objet;
      joueur_t ** liste_joueur;
      int nb_zombie;
      int nb_joueur;
}case_t;

#endif

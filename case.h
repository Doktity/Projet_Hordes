#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

typedef enum{
      non_explore,
      explore_neutre,
      explore_zombie,
      ville
}etat_case;

typedef struct {
      etat_case etat;
      objet_t ** liste_objet;
      joueur_t ** liste_joueur;
      int nb_zombie;
      int nb_joueur;
}case_t;

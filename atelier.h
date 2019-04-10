#ifndef _ATELIER_H_
#define _ATELIER_H_

#include "banque.h"


void atelier(banque_t *, liste_objet_t *, joueur_t * j);

objet_t * trouver_objet_vfinal(liste_objet_t *, char *);

void transformation(banque_t *, liste_objet_t *, joueur_t *);

#endif

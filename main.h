#include <stdio.h>
#include <time.h>
#include "joueur.h"
/*#include "carte.h"*/

#define DIX 6

typedef struct objet_s objet_t;

typedef struct {
  int nb_tour;
  time_t temps;
}tour_t;

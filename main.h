#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

//#include "joueur.h"
#include "carte.h"

#define DIX 600


typedef struct {
  int nb_tour;
  time_t temps;
}tour_t;


#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include "joueur.h"
#include "objet.h"
#include "carte.h"
#include "banque.h"
#include "maison.h"
#include "puit.h"

#define DIX 6
#define NB_ZOMBIE_MIN 10
#define NB_ZOMBIE_MAX 250


typedef struct {
  int nb_tour;
  time_t temps;
}tour_t;

#endif

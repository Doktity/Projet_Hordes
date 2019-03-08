#include <stdio.h>
#include "main.h"

typedef struct joueur_s{
  char * nom;
  int pa;
  objet_t inventaire[4];
  int statut[7];
} joueur_t;

joueur_t * Creer_Joueur(char * nom, int pa, objet_t inventaire[4], int statut[7]); // Renvoie le joueur_t du joueur qu'on a créer.

void Supprimer_Joueur(joueur_t * joueur); // Supprime le joueur.

int Est_Clair(joueur_t * joueur); // Renvoie 1 si le joueur est clair, 0 sinon.

int Est_Soif(joueur_t * joueur); // Renvoie 1 si le joueur est assoifé, 0 sinon.

int Est_Fatigue(joueur_t * joueur); // Renvoie 1 si le joueur est fatigué, 0 sinon.

int Est_Blessure(joueur_t * joueur); // Renvoie 1 si le joueur est blessé, 0 sinon.

int Est_Drogue(joueur_t * joueur); // Renvoie 1 si le joueur est drogué, 0 sinon.

int Est_Rassasie(joueur_t * joueur); // Renvoie 1 si le joueur est rassasié, 0 sinon.

int Est_Immunise(joueur_t * joueur); // Renvoie 1 si le joueur est immunisé, 0 sinon.

#include <stdio.h>
#include "joueur.h"


joueur_t * Creer_Joueur(char * nom, int pa, objet_t inventaire[3], int statut[6]){

  joueur_t * joueur = malloc(sizeof(joueur_t));
  int i;

  joueur->nom = nom;
  joueur->pa = pa;
  for(i=0; i<3; i++){
    joueur->inventaire[i] = inventaire[i];
  }
  for(i=0; i<6; i++){
    joueur->statut[i] = statut[i];
  }
  return joueur;
}

void Supprimer_Joueur(joueur_t * joueur){
  free(joueur);
  joueur = NULL;
}

int Est_Clair(joueur_t * joueur){
  return joueur->statut[0];
}

int Est_Soif(joueur_t * joueur){
  return joueur->statut[1];
}

int Est_Fatigue(joueur_t * joueur){
  return joueur->statut[2];
}

int Est_Blessure(joueur_t * joueur){
  return joueur->statut[3];
}

int Est_Drogue(joueur_t * joueur){
  return joueur->statut[4];
}

int Est_Rassasie(joueur_t * joueur){
  return joueur->statut[5];
}

int Est_Immunise(joueur_t * joueur){
  return joueur->statut[6];
}

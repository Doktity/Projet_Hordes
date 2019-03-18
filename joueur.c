#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"


joueur_t * Creer_Joueur(char * nom){

  joueur_t * joueur = malloc(sizeof(joueur_t));

  joueur->nom = nom;
  joueur->pa = 6;
  joueur->inventaire = {NULL, NULL, NULL, NULL};
  joueur->statut = {1, 0, 0, 0, 0, 0, 0};
  joueur->maison = 1;
  
  return joueur;
}


void Supprimer_Joueur(joueur_t * joueur){
  free(nom);
  nom = NULL;
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


void Afficher_inventaire(joueur_t * joueur){
  int i;
  for(i = 0; i<TAILLE_INVENTAIRE; i++){
    if(inventaire[i] != NULL){
      printf("Emplacement %d : %s\n", i+1, inventaire[i]->nom);
    }
  }
}


void  Trier_inventaire(joueur_t * joueur){
  int i;
  for(i=0; i<TAILLE_INVENTAIRE-1; i++){
    if(joueur->inventaire[i] == NULL){
      joueur->inventaire[i] = joueur->inventaire[i+1];
      joueur->inventaire[i+1] = NULL;
    }
  }
}



#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"


joueur_t * creer_joueur(char * nom){

  joueur_t * joueur = malloc(sizeof(joueur_t));

  int i;

  joueur->nom = nom;
  joueur->pa = 6;

  for(i = 0; i<TAILLE_INVENTAIRE; i++){
    joueur->inventaire[i] = NULL;
  }

  for(i = 1; i<NB_STATUT; i++){
    joueur->statut[i] = 0;
  }

  joueur->statut[0] = 1;
  joueur->maison = 1;
  objet_init_liste(&joueur->coffre);
  joueur->posx = 6;
  joueur->posy = 6;

  return joueur;
}


void supprimer_Joueur(joueur_t * joueur){
  free(joueur->nom);
  joueur->nom = NULL;
  free(joueur);
  joueur = NULL;
}


int est_Clair(joueur_t * joueur){
  return joueur->statut[0];
}


int est_Soif(joueur_t * joueur){
  return joueur->statut[1];
}


int est_Fatigue(joueur_t * joueur){
  return joueur->statut[2];
}


int est_Blessure(joueur_t * joueur){
  return joueur->statut[3];
}


int est_Drogue(joueur_t * joueur){
  return joueur->statut[4];
}


int est_Rassasie(joueur_t * joueur){
  return joueur->statut[5];
}


int est_Immunise(joueur_t * joueur){
  return joueur->statut[6];
}


void afficher_inventaire(joueur_t * joueur){
  int i;
  for(i = 0; i<TAILLE_INVENTAIRE; i++){
    if(joueur->inventaire[i] != NULL){
      printf("Emplacement %d : %s\n", i+1, joueur->inventaire[i]->nom_obj);
    }else{
      printf("Emplacement %d : vide\n", i+1);
    }
  }
}


void  trier_inventaire(joueur_t * joueur){
  int i;
  for(i=0; i<TAILLE_INVENTAIRE-1; i++){
    if(joueur->inventaire[i] == NULL){
      joueur->inventaire[i] = joueur->inventaire[i+1];
      joueur->inventaire[i+1] = NULL;
    }
  }
}


int inventaire_vide(joueur_t * joueur){
  int i;
  for(i = 0; i < TAILLE_INVENTAIRE && joueur->inventaire[i] != NULL; i++);
  return (i != TAILLE_INVENTAIRE);

}

#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"


joueur_t * creer_joueur(char * nom){

  joueur_t * joueur = malloc(sizeof(joueur_t));

  int i;

  strcpy(joueur->nom, nom);
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


void supprimer_joueur(joueur_t * joueur){
  free(joueur->nom);
  joueur->nom = NULL;
  free(joueur);
  joueur = NULL;
}


int est_clair(joueur_t * joueur){
  return joueur->statut[etat_clair];
}


int est_soif(joueur_t * joueur){
  return joueur->statut[etat_soif];
}


int est_fatigue(joueur_t * joueur){
  return joueur->statut[etat_fatigue];
}


int est_blesse(joueur_t * joueur){
  return joueur->statut[etat_blesse];
}


int est_drogue(joueur_t * joueur){
  return joueur->statut[etat_drogue];
}


int est_rassasie(joueur_t * joueur){
  return joueur->statut[etat_rassasie];
}


int est_immunise(joueur_t * joueur){
  return joueur->statut[etat_immunise];
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

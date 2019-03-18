#include "puit.h"

void puit (int * ration, joueur_t * joueur){
  int choix;
  
  do
  /* Affichage du menu et saisie du choix */
  {
    printf("\nPuit\n----\nQue voulez-vous faire ?\n");
    printf(" 1 - Prendre une ration d'eau\n");
    printf(" 2 - Rajouter de l'eau\n");
    printf(" 3 - Retour\n");
    printf("Votre choix : ");
    scanf("%d",&choix);

    /* Traitement du choix de l'utilisateur */
    switch(choix)
    {
      case 1: prendre_eau(ration, joueur); break;
      case 2: ajouter_eau(ration, joueur); break;
      case 3: break;
      default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
    }
  }
  while(choix!=3);
}


void prendre_eau (int * ration, joueur_t * joueur){
  
}


void ajouter_eau (int * ration, joueur_t * joueur){

}

#include "puit.h"

void puit (int * ration, joueur_t * joueur, liste_objet_t * liste){
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
      case 1: prendre_eau(ration, joueur, liste); break;
      case 2: ajouter_eau(ration, joueur, liste); break;
      case 3: break;
      default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
    }
  }
  while(choix!=3);
}


void prendre_eau (int * ration, joueur_t * joueur, liste_objet_t * liste){
  int i;
  char * nom = "eau";

  for(i = 0; i < TAILLE_INVENTAIRE && joueur->inventaire[i] != NULL; i++);

  if(i != TAILLE_INVENTAIRE){

    *joueur->inventaire[i] = trouver_objet(liste, nom);
    ration--;

  }else{
    printf("Vous n'avez pas de place dans votre inventaire !\n");
  }
}


void ajouter_eau (int * ration, joueur_t * joueur, liste_objet_t * liste){
  int i;
  char * nom = "eau";

  for(i = 0; i < TAILLE_INVENTAIRE && !strcmp(joueur->inventaire[i]->nom_obj, nom); i++);
  if(i != TAILLE_INVENTAIRE){
    joueur->inventaire[i] = NULL;
    ration++;
    trier_inventaire(joueur);
  }else{
    printf("Vous n'avez pas de ration d'eau !\n");
  }
}

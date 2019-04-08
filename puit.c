#include "puit.h"

void puit (int choix, int * ration, joueur_t * joueur, liste_objet_t * liste){

	/* Traitement du choix de l'utilisateur */
	switch(choix)
	{
		case 1: prendre_eau(ration, joueur, liste);
				break;
		case 2: ajouter_eau(ration, joueur, liste);
				break;
	}

}


void prendre_eau (int * ration, joueur_t * joueur, liste_objet_t * liste){
  int i;
  char * nom = "eau";
  for(i = 0; i < TAILLE_INVENTAIRE && joueur->inventaire[i] != NULL; i++);
  if(i != TAILLE_INVENTAIRE){
    joueur->inventaire[i] = trouver_objet(liste, nom);
    ration--;
  }else{
    printf("Vous n'avez pas la place dans votre inventaire !\n");
  }
}


void ajouter_eau (int * ration, joueur_t * joueur, liste_objet_t * liste){
  int i, ajout = 0;
  char * nom = "eau";

  for(i = 0; i < TAILLE_INVENTAIRE && joueur->inventaire[i] != NULL; i++){
    if(strcmp(joueur->inventaire[i]->nom_obj, nom) == 0 && ajout == 0){
      joueur->inventaire[i] = NULL;
      ration++;
      trier_inventaire(joueur);
      ajout++;
      printf("Ajout effectué.\n");
    }
  }

  if(ajout == 0){
    printf("Vous n'avez pas de ration d'eau dans votre inventaire !\n");
  }
}

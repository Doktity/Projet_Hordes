#include "maison.h"

void maison(int choix, joueur_t * joueur){

	/* Traitement du choix de l'utilisateur */
	switch(choix)
	{
		case 1: ameliorer_maison(joueur);
				break;
		case 2: afficher_inventaire(joueur);
				objet_afficher_liste(joueur->coffre);
				break;
		case 3: utiliser_objet(joueur);
				break;
		case 4: deposer_objet(joueur->coffre, joueur); 
				break;
		case 5: prendre_objet(joueur->coffre, joueur);
				break;
	}
}


void ameliorer_maison(joueur_t * joueur){
  switch(joueur->maison)
  {
    case 1: if(joueur->pa >= 2){
              joueur->maison++;
              joueur->pa -= 2;
              printf("Amélioration réussie.\n");
            }else{
              printf("Pas assez de points d'actions ! (besoin de 2 pa)\n");
            }
            break;
    case 2:
    case 3: if(joueur->pa == 6){
              joueur->maison++;
              joueur->pa -= 6;
              printf("Amélioration réussie.\n");
            }else{
              printf("Pas assez de points d'actions ! (besoin de 6 pa)\n");
            }
            break;
    default: printf("Amélioration maximum de la maison atteint");
  }
}

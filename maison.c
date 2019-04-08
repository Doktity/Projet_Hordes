#include "maison.h"

void maison(int choix, joueur_t * joueur, char * buffer){
  char mem[512];

	/* Traitement du choix de l'utilisateur */
	switch(choix)
	{
		case 1: sprintf(buffer, "%s", ameliorer_maison(joueur));
				break;
		case 2: objet_afficher_liste(joueur->coffre, buffer);
            strcpy(mem, buffer);
            afficher_inventaire(joueur, buffer);
            strcat(buffer, mem);
				break;
		case 3: utiliser_objet(joueur);
				break;
		case 4: deposer_objet(joueur->coffre, joueur); 
				break;
		case 5: prendre_objet(joueur->coffre, joueur);
				break;
	}
}


char * ameliorer_maison(joueur_t * joueur){
  switch(joueur->maison)
  {
    case 1: if(joueur->pa >= 2){
              joueur->maison++;
              joueur->pa -= 2;
              return "Amélioration réussie.";
            }else{
              return "Pas assez de points d'actions ! (besoin de 2 pa)";
            }
            break;
    case 2:
    case 3: if(joueur->pa == 6){
              joueur->maison++;
              joueur->pa -= 6;
              return "Amélioration réussie.";
            }else{
              return "Pas assez de points d'actions ! (besoin de 6 pa)";
            }
            break;
    default: return "Amélioration maximum de la maison atteint";
  }
}

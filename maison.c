#include "maison.h"

void maison(joueur_t * joueur){
  do
  /* Affichage du menu et saisie du choix */
  {
    printf("\nMaison\n------\nQue voulez-vous faire ?\n");
    printf(" 1 - Améliorer maison\n");
    printf(" 2 - Voir inventaire et coffre\n");
    printf(" 3 - Utiliser objet\n");
    printf(" 4 - Deposer objet\n");
    printf(" 5 - Prendre objet\n");
    printf(" 6 - Retour\n");
    printf("Votre choix : ");
    scanf("%d",&choix);

    /* Traitement du choix de l'utilisateur */
    switch(choix)
    {
      case 1: ameliorer_maison(joueur); break;
      case 2: Afficher_inventaire(joueur); afficher_liste(joueur->coffre); break;
      case 3: utiliser_objet(joueur); break;
      case 4: deposer_objet(joueur->coffre, joueur); break;
      case 5: prendre_objet(joueur->coffre, joueur);break;
      case 6: break;
      default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
    }
  }
  while(choix!=6);
}


ameliorer_maison(joueur_t * joueur){
  switch(joueur->maison)
  {
    case 1: if(joueur->pa >= 2){
              joueur->maison++;
              joueur->pa -= 2;
              printf("Amélioration réussie.\n");
            }else{
              printf("Pas assez de points d'actions ! (besoin de 2 pa)\n");
            }
    case 2:
    case 3: if(joueur->pa == 6){
              joueur->maison++;
              joueur->pa -= 6;
              printf("Amélioration réussie.\n");
            }else{
              printf("Pas assez de points d'actions ! (besoin de 6 pa)\n");
            }
    default: printf("Amélioration maximum de la maison atteint");
  }
}

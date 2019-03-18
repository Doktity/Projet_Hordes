#include "maison.h"

void maison(t_joueur * joueur){
  do
  /* Affichage du menu et saisie du choix */
  {
    printf("\nMaison\n------\nQue voulez-vous faire ?\n");
    printf(" 1 - Améliorer maison\n");
    printf(" 2 - Utiliser objet\n");
    printf(" 3 - Voir inventaire\n");
    printf(" 4 - Retour\n");
    printf("Votre choix : ");
    scanf("%d",&choix);

    /* Traitement du choix de l'utilisateur */
    switch(choix)
    {
      case 1: ameliorer_maison(joueur); break;
      case 2: utiliser_objet(joueur); break;
      case 3: afficher_inventaire(joueur); break;
      case 4: break;
      default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
    }
  }
  while(choix!=4);
}


ameliorer_maison(t_joueur * joueur){
  switch(joueur->maison)
  {
    case 1: if(joueur->pa >= 2){
              joueur->maison++;
              joueur->pa -= 2;
            }else{
              printf("Pas assez de points d'actions ! (besoin de 2 pa)\n");
            }
    case 2:
    case 3: if(joueur->pa == 6){
              joueur->maison++;
              joueur->pa -= 6;
            }else{
              printf("Pas assez de points d'actions ! (besoin de 6 pa)\n");
            }
    default: printf("Amélioration maximum de la maison atteint");
  }
}

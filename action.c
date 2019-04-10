#include <stdio.h>
#include <stdlib.h>

#include "action.h"

void deposer_objet(liste_objet_t * l, joueur_t * joueur){

  int num;

  //afficher_inventaire(joueur);
  if(!inventaire_vide(joueur)){
      do{
      printf("Donner le numéro de case de l'objet que vous voulez déposer (1,2,3,4): ");
      scanf("%i", &num);
      }while(num>4 || num<0);

      objet_ajout_droit(*joueur->inventaire[num-1], l);
      joueur->inventaire[num-1] = NULL;
      trier_inventaire(joueur);
  }else{
        printf("Votre inventaire est vide !\n");
  }

}


void prendre_objet (liste_objet_t * l, joueur_t * joueur){
      int i;
      char * nom_objet;

      for(i = 0; i < TAILLE_INVENTAIRE && joueur->inventaire[i] != NULL; i++);
      if(i != TAILLE_INVENTAIRE){

            //objet_afficher_liste(l);

            do{
                  printf("Donner le nom de l'objet que vous voulez prendre : ");
                  scanf("%s", nom_objet);
            }while(!est_present_objet(l, nom_objet));

            joueur->inventaire[i] = trouver_objet(l, nom_objet);
            supprimer_objet(l, nom_objet);

      }else{
            printf("Vous n'avez pas la place dans votre inventaire !\n");
      }
}

void utiliser_objet (joueur_t * joueur){

      int num;
      //afficher_inventaire(joueur);

      if(!inventaire_vide(joueur)){
            do{
                  printf("Donner le numéro de case de l'objet que vous voulez déposer (1,2,3,4): ");
                  scanf("%i", &num);
            }while(num>4 || num<0);

            /*UTILISER OBJET*/
            printf("Oui bonjour c'est la fonction utiliser objet faut me finir heho\n");

      }else{
            printf("Votre inventaire est vide !\n");
      }


}


int nb_aleatoire(int ecart){
      return(rand()%ecart);
}

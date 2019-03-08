#include "main.h"

int main(){

  time_t depart;
  tour_t tour;
  tour.nb_tour = 1;
  int nb_t = 0;
  depart = time(NULL);

  joueur_t * joueur;
  char * nom;
  objet_t inventaire[4];
  int statut[] = {0,0,0,0,1,0,0};

  printf("Nom ? : ");
  scanf("%s", nom);

  joueur = Creer_Joueur(nom, 6, inventaire, statut);

  printf("Bonjour %s !\n", joueur->nom);

  while(tour.nb_tour < 10){
      tour.temps = time(NULL);
      if((tour.temps - depart) >= DIX){
        depart += DIX;
        tour.nb_tour++;
      }
      if(nb_t != tour.nb_tour){
        printf("%d tours.\n", tour.nb_tour);
        nb_t = tour.nb_tour;
      }
  }

  return 0;

}

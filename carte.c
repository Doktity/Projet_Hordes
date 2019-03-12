#include "carte.h"

t_mat * creer_carte(){
      case_t type;
      //initialisation de la carte
      t_mat * map = alouer_matrice(T,T,&type);
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  map->mat[i][j].etat = non_explore;
                  map->mat[i][j].nb_joueur=0;
                  map->mat[i][j].nb_zombie=0;
            }
      }
      map->mat[(map->nbl)/2][(map->nbc)/2].etat = ville;
      return map;
}

void afficher_carte(t_mat * map){
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  if (map->mat[i][j].nb_joueur) {
                        printf("%i",map->mat[i][j].nb_joueur);
                  }
                  else{
                        printf(" ");
                  }
                  switch (map->mat[i][j].etat) {
                        case ville:printf("v ");break;
                        case non_explore:printf("ø ");break;
                        case explore_neutre:printf("o ");break;
                        case explore_zombie:printf("z%i",map->mat[i][j].nb_zombie);break;
                        default:printf("?");
                  }
            }
            printf("\n\n");
      }
}

void afficher_carte(t_mat * map){
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  if (map->mat[i][j].nb_joueur) {
                        printf("%i",map->mat[i][j].nb_joueur);
                  }
                  else{
                        printf(" ");
                  }
                  switch (map->mat[i][j].etat) {
                        case ville:printf("v ");break;
                        case non_explore:printf("ø ");break;
                        case explore_neutre:printf("o ");break;
                        case explore_zombie:printf("z%i",map->mat[i][j].nb_zombie);break;
                        default:printf("?");
                  }
            }
            printf("\n\n");
      }
}

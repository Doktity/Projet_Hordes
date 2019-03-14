#include "carte.h"

t_mat * creer_carte(){
      //initialisation de la carte
      t_mat * map = alouer_matrice(T,T);
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

t_mat * calculer_pos_zombie(t_mat * map, int nb_jour){
      nb_jour ++;
      int nb_zombie_today =(int) log(nb_jour)*2+nb_jour-1;

      for (int i = 0; i < nb_zombie_today; i++) {
            int x,y;
            do {
                  x = nb_aleatoire(map->nbl);
                  y = nb_aleatoire(map->nbc);
            } while(x == (map->nbl)/2 && y == (map->nbc)/2);//tant que c'est égal à la position de la ville
            map->mat[x][y].nb_zombie ++;
      }
}


int main(int argc, char const *argv[]) {
      
      return 0;
}

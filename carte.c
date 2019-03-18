#include "carte.h"

t_mat * creer_carte(){
      //initialisation de la carte
      t_mat * map = allouer_matrice(T,T);
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

t_mat * calculer_pos_zombie(t_mat * map, int nb_jour, int nb_zombie_hier){

      nb_zombie_today=(int)log(nb_jour)*10+nb_zombie_hier;

      for (int i = 0; i < nb_zombie_today; i++) {
            int x,y;
            do {
                  x = nb_aleatoire(map->nbl);
                  y = nb_aleatoire(map->nbc);
            } while(x == (map->nbl)/2 && y == (map->nbc)/2);//tant que c'est égal à la position de la ville
            map->mat[x][y].nb_zombie ++;
      }
}

/*
void action(int posx, int posy, joueur_t joueur,t_mat map){
      int i = 1,choix;
      printf("quels actions voulez vous faire ?\n");
      if (posx) {
            printf("%i:vous déplacer à gauche\n",i);
            i++;
      }
      if (!(posx==map->nbc-1)) {
            printf("%i:vous déplacer à droite\n",i);
            i++;
      }
      if (posy) {
            printf("%i:vous déplacer en haut\n",i);
            i++;
      }
      if (!(posy==map->nbl-1)) {
            printf("%i:vous déplacer en bas\n",i);
            i++;
      }
      printf("%i:fouiller la zone\n",i);
      if (map->mat[posx][posy].nb_zombie) {
            printf("%i:attaquer un zombie\n", i);
            i++;
      }
      if (!liste_vide(map->mat->liste_objet)) {
            printf("%i:ramasser objets\n",i);
      }
      scanf("%i\n", &choix);
      switch (choix) {
            case :
      }*/
}

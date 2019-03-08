#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"


#include "objet_t.h"
#include "joueur_t.h"
#define T  13//taille des côtés de la carte




t_mat * creer_carte(){
      case_t type;
      //initialisation de la carte
      t_mat * map = alouer_matrice(T,T,&type);
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  map->mat[i][j].etat = non_explore;
            }
      }
      map->mat[(map->nbl)/2+1][(map->nbc)/2+1].etat = ville;
      return map;
}

void afficher_carte(t_mat * map){
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  switch (map->mat[i][j].etat) {
                        case ville:printf("v");break;
                        case non_explore:printf("ø");break;
                        case explore_neutre:printf("o");break;
                        case explore_zombie:printf("z");break;
                  }
            }
      }
}


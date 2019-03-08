#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"


//#include "objet_t.h"
//#include "joueur_t.h"
#define T  13//taille des côtés de la carte




t_mat * creer_carte(){
      case_t type;
      //initialisation de la carte
      t_mat * map = alouer_matrice(T,T,&type);
      map->mat[(map->nbl)/2+1][(map->nbc)/2+1].etat = ville;
      return map;
}

void afficher_carte(t_mat * map){
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  switch (map->mat[i][j].etat) {
                        case ville:printf("v\n");
                  }
            }
      }
}
/*void afficher_carte(int * map) {
      for (int i = 0; i < T; i++) {
            for (int k = 0; k < 3; k++) {
                  for (int j = 0; j < T; j++) {
                        if (k==0) {
                              if (*map==vide) {
                                    printf("   ");
                              }
                              else if (*map==ville) {
                                    printf("↘↔↙");
                              }
                              else if (*map==perso){
                                    printf("   ");
                               }
                        }
                        else if (k==1) {
                              if (*map==vide) {
                                    printf(" 0 ");
                              }
                              else if (*map==ville) {
                                    printf("↕V↕");
                              }
                              else if (*map==perso){
                                    printf(" Y ");
                              }
                        }
                        else{
                              if (*map==vide) {
                                    printf("   ");
                              }
                              else if (*map==ville) {
                                    printf("↗↔↖");
                              }
                              else if (*map==perso){
                                    printf("   ");
                              }
                        }
                        map++;
                  }
                  map-=T;
                  printf("\n");
            }
            map+=T;

      }
}*/

#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "objet_t.h"
##include "joueur_t.h"
#define T  13//taille des côtés de la carte

typedef enum{
      non_explore,
      explore_neutre,
      explore_zombie,
      ville
}etat_case;

typedef struct {
      etat_case etat;
      objet_t ** liste_objet;
      joueur_t ** liste_joueur;
      int nb_zombie;
}case_t;


int * creer_carte(){
      case_t type;
      //initialisation de la carte
      t_mat * map = alouer_matrice(T,T,type);

      return map;
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

int main(int argc, char const *argv[]) {
      int * map;

      map = creer_carte(map);
      printf("ici\n");
      afficher_carte(map);
      return 0;
}

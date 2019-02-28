#include <stdio.h>
#include <stdlib.h>

#define T  13//taille des côtés de la carte
#define ville 1
#define vide 0
#define perso 2
#define ok printf("ok\n");

int * creer_carte(){
      //initialisation de la carte
      int *map=malloc(T*T*sizeof(int));
      for (int i = 0; i < T*T; i++) {
            map[i]=vide;
      }
      //placement de la ville en milieu de carte
      map[T/2*T+T/2]=ville;


      return map;
}

void afficher_carte(int * map) {
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
}

int main(int argc, char const *argv[]) {
      int * map;

      map = creer_carte(map);
      printf("ici\n");
      afficher_carte(map);
      return 0;
}

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

void action(int posx, int posy, joueur_t joueur,t_mat map){
      int i = 1;
      printf("quels actions voulez vous faire ?\n");
      if (!posx) {
            printf("%i:vous déplacer à gauche\n",i);
            i++;
      }
      if (!(posx==map->nbc-1)) {
            printf("%i:vous déplacer à droite\n",i);
            i++;
      }
      if (!posy) {
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
            printf("%i:ramasser les objets\n",i);
      }


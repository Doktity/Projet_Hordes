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
      system("clear");
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
      //remettre le nombre de zombie de la carte à 0
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  map->mat[i][j].nb_zombie=0;
            }
      }
      //
      int nb_zombie_today=(int)log(nb_jour)*10+nb_zombie_hier;

      for (int i = 0; i < nb_zombie_today; i++) {
            int x,y;
            do {
                  x = nb_aleatoire(map->nbl);
                  y = nb_aleatoire(map->nbc);
            } while(x == (map->nbl)/2 && y == (map->nbc)/2);//tant que c'est égal à la position de la ville
            map->mat[x][y].nb_zombie ++;
      }
      return map;
}


static void gauche(joueur_t * joueur,t_mat * map) {
      if (joueur->posx) {//si la position de la case du joueur n'est pas toute à gauche
            joueur->posx--;
            if (map->mat[posx][posy].etat==non_explore) {
                  if (map->mat[posx][posy].nb_zombie) {
                        map->mat[posx][posy].etat=explore_zombie;
                  }
                  else{
                        map->mat[posx][posy].etat=explore_neutre;
                  }
            }
      }
}

static void droite(joueur_t * joueur,t_mat * map){
      if (joueur->posx!=map->nbc) {//si la position de la case du joueur n'est pas toute à droite
            joueur->posx ++;
            if (map->mat[posx][posy].etat==non_explore) {
                  if (map->mat[posx][posy].nb_zombie) {
                        map->mat[posx][posy].etat=explore_zombie;
                  }
                  else{
                        map->mat[posx][posy].etat=explore_neutre;
                  }
            }
      }
}

static void haut(joueur_t * joueur,t_mat * map){
      if (joueur->posy) {//si la position de la case du joueur n'est pas tout en haut
            joueur->posy--;
            if (map->mat[posx][posy].etat==non_explore) {
                  if (map->mat[posx][posy].nb_zombie) {
                        map->mat[posx][posy].etat=explore_zombie;
                  }
                  else{
                        map->mat[posx][posy].etat=explore_neutre;
                  }
            }
      }
}

static void bas(joueur_t * joueur,t_mat * map){
      if (joueur->posy!=map->nbl) {//si la position de la case du joueur n'est pas tout en bas
            joueur->posy++;
            if (map->mat[posx][posy].etat==non_explore) {
                  if (map->mat[posx][posy].nb_zombie) {
                        map->mat[posx][posy].etat=explore_zombie;
                  }
                  else{
                        map->mat[posx][posy].etat=explore_neutre;
                  }
            }
      }
}

static void fouiller(joueur_t * joueur,t_mat * map){
      int nb_objet  = nb_aleatoire();

}

static void attaquer(joueur_t * joueur,t_mat * map){

}

static void ramasser(joueur_t * joueur,t_mat * map){

}

void action_carte(joueur_t * joueur, t_mat * map){
      system("clear");
      int choix;

      do{
            printf(" Quels actions voulez vous faire ?\n");
            printf(" 1 - vous déplacer à gauche\n");
            printf(" 2 - vous déplacer à droite\n");
            printf(" 3 - vous déplacer en haut\n");
            printf(" 4 - vous déplacer en bas\n");
            printf(" 5 - fouiller la zone\n");
            printf(" 6 - attaquer un zombie\n");
            printf(" 7 - ramasser objets\n");
            printf(" 8 - afficher la carte\n");
            printf(" 9 - sortir de la carte\n");

            scanf("%i", &choix);


            switch (choix) {
                  case 1:gauche(joueur,map);    break;
                  case 2:droite(joueur,map);    break;
                  case 3:haut(joueur,map);      break;
                  case 4:bas(joueur,map);       break;
                  case 5:fouiller(joueur,map);  break;
                  case 6:attaquer(joueur,map);  break;
                  case 7:ramasser(joueur,map);  break;
                  case 8:afficher_carte(map);   break;
                  case 9:printf("bye bye\n");   break;
                  default: printf("erreur de choix\n");
            }
      }while (choix!=9);
}

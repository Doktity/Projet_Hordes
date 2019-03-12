#include "action.h"
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
}

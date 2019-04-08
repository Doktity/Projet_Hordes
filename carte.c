#include "carte.h"



t_mat * creer_carte(){
      //initialisation de la carte
      t_mat * map = allouer_matrice(T,T);
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  map->mat[i][j].etat = non_explore;
                  map->mat[i][j].nb_joueur=0;
                  map->mat[i][j].nb_zombie=0;
                  map->mat[i][j].fouille = non_fouillee;
                  objet_init_liste(&(map->mat[i][j].objet_sol));
            }
      }
      map->mat[(map->nbl)/2][(map->nbc)/2].etat = ville;
      return map;
}

void afficher_carte(t_mat * map){
      system("clear");
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  if (map->mat[j][i].nb_joueur) {
                        printf("%i",map->mat[j][i].nb_joueur);
                  }
                  else{
                        printf(" ");
                  }
                  switch (map->mat[j][i].etat) {
                        case ville:printf("v ");break;
                        case non_explore:printf("ø ");break;
                        case explore_neutre:printf("o ");break;
                        case explore_zombie:printf("z%i",map->mat[j][i].nb_zombie);break;
                        default:printf("?");
                  }
            }
            printf("\n\n");
      }
}

int tour_de_jeu(t_mat * map, int nb_jour, int nb_zombie_hier){
      //réinitialisation de la carte
      for (int i = 0; i < map->nbl; i++) {
            for (int j = 0; j < map->nbc; j++) {
                  if (map->mat[i][j].etat != ville) {
                        map->mat[i][j].nb_zombie = 0;
                        map->mat[i][j].etat=non_explore;
                        map->mat[i][j].fouille = non_fouillee;
                        map->mat[i][j].nb_joueur = 0;
                  }
            }
      }
      joueur_en_tete();
      while (!joueur_hors_liste()) {
            joueur_t * mem;
            joueur_valeur_elt(&mem);
            if (mem->posx != 6 || mem->posy != 6) {
                  joueur_oter_elt();
                  supprimer_joueur(mem);
            }
            else{
                  joueur_suivant();
            }
      }
      int nb_zombie_today=(int)log(nb_jour)*12+nb_zombie_hier;

      for (int i = 0; i < nb_zombie_today; i++) {
            int x,y;
            do {
                  x = nb_aleatoire(map->nbl);
                  y = nb_aleatoire(map->nbc);
            } while(x == (map->nbl)/2 && y == (map->nbc)/2);//tant que c'est égal à la position de la ville
            map->mat[x][y].nb_zombie ++;
      }
      return nb_zombie_today;
}


static void gauche(joueur_t * joueur,t_mat * map) {
      if (!joueur->pa) {
            printf("Vous n'avez pas assez de Points d'action\n");
      }
      else{
            if (joueur->posx) {//si la position de la case du joueur n'est pas toute à gauche
                  map->mat[joueur->posx][joueur->posy].nb_joueur --;
                  joueur->posx--;
                  map->mat[joueur->posx][joueur->posy].nb_joueur ++;
                  if (map->mat[joueur->posx][joueur->posy].etat==non_explore) {
                        if (map->mat[joueur->posx][joueur->posy].nb_zombie) {
                              map->mat[joueur->posx][joueur->posy].etat=explore_zombie;
                        }
                        else{
                              map->mat[joueur->posx][joueur->posy].etat=explore_neutre;
                        }
                  }

                  joueur->pa--;
            }
            else{
                  printf("Il ne vous es malheureusement impossible d'aller plus à gauche, vous n'y trouverez que des zombies, coisissez une autre direction!!\n");
            }
      }
}

static void droite(joueur_t * joueur,t_mat * map){
      if (!joueur->pa) {
            printf("Vous n'avez pas assez de Points d'action\n");
      }
      else{
            if (joueur->posx!=map->nbc) {//si la position de la case du joueur n'est pas toute à droite
                  map->mat[joueur->posx][joueur->posy].nb_joueur --;
                  joueur->posx ++;
                  map->mat[joueur->posx][joueur->posy].nb_joueur ++;
                  if (map->mat[joueur->posx][joueur->posy].etat==non_explore) {
                        if (map->mat[joueur->posx][joueur->posy].nb_zombie) {
                              map->mat[joueur->posx][joueur->posy].etat=explore_zombie;
                        }
                        else{
                              map->mat[joueur->posx][joueur->posy].etat=explore_neutre;
                        }
                  }
                  joueur->pa--;
            }
            else{
                  printf("Vous ne trouverez rien si vous allez plus à droite choisissez une autre direction!!\n");
            }
      }
}

static void haut(joueur_t * joueur,t_mat * map){
      if (!joueur->pa) {
            printf("Vous n'avez pas assez de Points d'action\n");

      }
      else{
            if (joueur->posy) {//si la position de la case du joueur n'est pas tout en haut
                  map->mat[joueur->posx][joueur->posy].nb_joueur --;
                  joueur->posy--;
                  map->mat[joueur->posx][joueur->posy].nb_joueur ++;
                  if (map->mat[joueur->posx][joueur->posy].etat==non_explore) {
                        if (map->mat[joueur->posx][joueur->posy].nb_zombie) {
                              map->mat[joueur->posx][joueur->posy].etat=explore_zombie;
                        }
                        else{
                              map->mat[joueur->posx][joueur->posy].etat=explore_neutre;
                        }
                  }
                  joueur->pa--;
            }
            else{
                  printf("Il vous est impossible de monter aux cieux vous etes déjà bien assez haut!!\n");

            }
      }
}

static void bas(joueur_t * joueur,t_mat * map){
      if (!joueur->pa) {
            printf("Vous n'avez pas assez de Points d'action\n");

      }
      else{
            if (joueur->posy!=map->nbl) {//si la position de la case du joueur n'est pas tout en bas
                  map->mat[joueur->posx][joueur->posy].nb_joueur --;
                  joueur->posy++;
                  map->mat[joueur->posx][joueur->posy].nb_joueur ++;
                  if (map->mat[joueur->posx][joueur->posy].etat==non_explore) {
                        if (map->mat[joueur->posx][joueur->posy].nb_zombie) {
                              map->mat[joueur->posx][joueur->posy].etat=explore_zombie;
                        }
                        else{
                              map->mat[joueur->posx][joueur->posy].etat=explore_neutre;
                        }
                  }
                  joueur->pa--;
            }
            else{
                  printf("Impossible, vous etes tout en bas de la carte, vous ne pouvez pas descendre aux enfers!!\n");

            }
      }
}

static void fouiller(joueur_t * joueur,t_mat * map, liste_objet_t * liste){

      if (map->mat[joueur->posx][joueur->posy].fouille == non_fouillee && map->mat[joueur->posx][joueur->posy].etat != ville) {
            map->mat[joueur->posx][joueur->posy].fouille == fouillee;
            objet_t * objet;
            int nb_objet  = nb_aleatoire(4), id_objet;
            nb_objet ++;
            for(int i = 0; i < nb_objet; i++){
                  printf("coucou\n");
                  id_objet = nb_aleatoire(NB_OBJET);
                  printf("ici\n");
                  objet = trouver_objet_n(liste, id_objet);
                  printf("hello\n");
                  objet_ajout_gauche(* objet, map->mat[joueur->posx][joueur->posy].objet_sol);
                  printf("là\n");
            }
      }
}


static void attaquer(joueur_t * joueur,t_mat * map){
      if (!joueur->pa) {
            printf("Vous n'aves pas assez de points d'action\n");
      }
      if (map->mat[joueur->posx][joueur->posy].nb_zombie && !est_blessure(joueur)) {
            map->mat[joueur->posx][joueur->posy].nb_zombie --;
            joueur->pa --;
            if(!nb_aleatoire(4)){//le joueur a une chance sur 4 d'etre blessé après avoir attaquer un zombie (si le nombre aléatoire == 0)
                  joueur->statut[3] = 1;//on met le statut de blessure à vrai
            }
      }

}


static void ramasser(joueur_t * joueur,t_mat * map){
      liste_objet_t * liste = map->mat[joueur->posx][joueur->posy].objet_sol;
      int nb_elem = 0, choix, i = 0;
      for (int i = 0; i < 4; i++) {
            if (joueur->inventaire[i]) {
                  nb_elem ++;
            }
      }
      if (nb_elem < 4) {
            objet_t courant;
            printf("quel objet voulez vous ramasser ?\n");
            //affichage des objet
            objet_en_tete(liste);
            while(!objet_hors_liste(liste)){
                objet_valeur_elt(&courant, liste);
                printf("%i : %s\n", i, courant.nom[objet]);
                objet_suivant(liste);
                i++;
            }
            //choix de l'objet
            do{
                scanf("%i",&choix);               
            } while (choix < 0 || choix > i);
            //récupération de l'objet
            objet_en_tete(liste);
            for(i = 0; i < choix; i++){
                objet_suivant(liste);
            }
            for(i = 0; joueur->inventaire[i]; i++);
            objet_valeur_elt(&courant,liste);
            joueur->inventaire[i] = courant;
            objet_oter_elt(liste);
            
            
      }
      else{
            printf("pas de place\n");
      }
}

static void utiliser(joueur_t * joueur){

}

static void sortir(joueur_t * joueur,int * choix){
      if (joueur->posx != 6 || joueur->posy != 6) {
            printf("vous ne pouvezpas sortir, vous n'etes pas aux coordonnées de la ville\n");
            *choix = 9;
      }
      else{
            printf("pressé de vous revoir dans l'outrel monde\n");
      }
}

void action_carte(joueur_t * joueur, t_mat * map,liste_objet_t * liste){
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
            printf(" 8 - utiliser un objet de votre sac\n");
            printf(" 9 - afficher la carte\n");
            printf(" 10 - sortir de la carte\n");

            scanf("%i", &choix);


            switch (choix) {
                  case 1:gauche(joueur,map);          break;
                  case 2:droite(joueur,map);          break;
                  case 3:haut(joueur,map);            break;
                  case 4:bas(joueur,map);             break;
                  case 5:fouiller(joueur,map,liste);  break;
                  case 6:attaquer(joueur,map);        break;
                  case 7:ramasser(joueur,map);        break;
                  case 8:utiliser(joueur);            break;
                  case 9:afficher_carte(map);         break;
                  case 10:sortir(joueur,&choix);      break;
                  default: printf("erreur de choix\n");
            }
      }while (choix!=10);
}

#include "banque.h"

void banque(int choix, banque_t * l, joueur_t * j){

    switch(choix){
        case 1: affiche_banque(l);
                break;
        case 2: if(!inventaire_vide(j)){
                    ajouter_objet_banque(l,j);
                }else{
                    printf("Votre inventaire est vide !\n");
                }
                break;
        case 3: retirer_objet_banque(l,j);
                break;
    }
}

void init_banque(banque_t * b){
   objet_init_liste(&b->nourriture);
   objet_init_liste(&b->drogue);
   objet_init_liste(&b->arme);
   objet_init_liste(&b->obj_construct);
}

void affiche_banque(banque_t * b){
    printf("Nourriture:\n");
    objet_afficher_liste(b->nourriture);
    printf("Drogue:\n");
    objet_afficher_liste(b->drogue);
    printf("Arme:\n");
    objet_afficher_liste(b->arme);
    printf("Objet de construction:\n");
    objet_afficher_liste(b->obj_construct);
}

void ajouter_objet_banque(banque_t * b, joueur_t * j){
    int choix;
    printf("Dans quel catégorie voulez-vous déposer votre objet?\n");
    printf("1 - Nourriture\n");
    printf("2 - Drogue\n");
    printf("3 - Arme\n");
    printf("4 - Objet de construction\n");
    scanf("%d",&choix);
    switch(choix){
          case 1:deposer_objet(b->nourriture,j); break;
          case 2:deposer_objet(b->drogue,j); break;
          case 3:deposer_objet(b->arme,j); break;
          case 4:deposer_objet(b->obj_construct,j); break;
          default:printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
     }
}

void retirer_objet_banque(banque_t * b,joueur_t * j){
    int choix;
    liste_objet_t * pt=NULL;
    printf("De quel catégorie voulez-vous prendre votre objet?\n");
    printf("1 - Nourriture\n");
    printf("2 - Drogue\n");
    printf("3 - Arme\n");
    printf("4 - Objet de construction\n");
    scanf("%d",&choix);
    switch(choix){
          case 1:pt=b->nourriture; break;
          case 2:pt=b->drogue; break;
          case 3:pt=b->arme; break;
          case 4:pt=b->obj_construct; break;
          default:printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
    }
    if(pt!=NULL){
        prendre_objet(pt,j);
    }
}

#include "banque.h"

void banque(banque_t * l, joueur_t * j){
  int choix;
    do{
        printf("Bienvenue à la banque\n");
        printf("Que voulez-vous faire?\n");
        printf(" 1 - Afficher la liste des objets de la banque\n");
        printf(" 2 - Ajouter un objet dans la banque\n");
        printf(" 3 - Prendre un objet de la banque\n");
        printf(" 4 - Quitter la banque\n");
        printf("Votre choix:");
        scanf("%d",&choix);
        switch(choix){
            case 1: affiche_banque(l); break;
            case 2: ajouter_objet_banque(l,j); break;
            case 3: retirer_objet_banque(l,j); break;
            case 4:break;
            default: printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
        }
    }while(choix!=4);
}

void init_banque(banque_t * b){
   objet_init_liste(&b->nourriture);
   objet_init_liste(&b->drogue);
   objet_init_liste(&b->arme);
   objet_init_liste(&b->transformable);
   objet_init_liste(&b->materiau);
}

void affiche_banque(banque_t * b){
    printf("Nourriture:\n");
    objet_afficher_liste(b->nourriture);
    printf("Drogue:\n");
    objet_afficher_liste(b->drogue);
    printf("Arme:\n");
    objet_afficher_liste(b->arme);
    printf("Objet transformable:\n");
    objet_afficher_liste(b->transformable);
    printf("Matériau:\n");
    objet_afficher_liste(b->materiau);
}

void ajouter_objet_banque(banque_t * b, joueur_t * j){
    int choix;
    printf("Dans quel catégorie voulez-vous déposer votre objet?\n");
    printf("1 - Nourriture\n");
    printf("2 - Drogue\n");
    printf("3 - Arme\n");
    printf("4 - Objet transformable\n");
    printf("5 - Matériau\n");
    scanf("%d", &choix);
    switch(choix){
          case 1:deposer_objet(b->nourriture,j); break;
          case 2:deposer_objet(b->drogue,j); break;
          case 3:deposer_objet(b->arme,j); break;
          case 4:deposer_objet(b->transformable,j); break;
          case 5:deposer_objet(b->materiau,j); break;
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
          case 4:pt=b->transformable; break;
          case 5:pt=b->materiau; break;
          default:printf("Erreur, vous devez entrer un chiffre entre 1 et 5\n");
    }
    if(pt!=NULL){
        prendre_objet(pt,j);
    }
}

#include "banque.h"

void banque(liste_objet_t *l, joueur * j){
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
            case 1: affiche_banque(l);break;
            case 2: ajouter_objet_banque(l,j);break;
            case 3: retirer_objet_banque(l,j);break;
            case 4:break;
            default: printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
        }
    }while(choix!=4);
}

void init_banque(banque_t b){
    init_liste(b.nourriture);
    init_liste(b.drogue);
    init_liste(b.arme);
    init_liste(b.obj_construct);
}

void afficher_banque(banque_t b){
    printf("Nourriture:\n");
    affiche_liste(banque.nourriture);
    printf("Drogue:\n");
    affiche_liste(banque.drogue);
    printf("Arme:\n");
    affiche_liste(banque.arme);
    printf("Objet de construction:\n");
    affiche_liste(banque.obj_construct);
}

void ajouter_objet_banque(banque_t  b,joueur_t * j){
    int choix;
    printf("Dans quel catégorie voulez-vous déposer votre objet?\n");
    printf("1 - Nourriture\n");
    printf("2 - Drogue\n");
    printf("3 - Arme\n");
    printf("4 - Objet de construction\n");
    scanf("%d",&choix);
    switch(choix){
          case 1:deposer_objet(b.nourriture,j); break;
          case 2:deposer_objet(b.drogue,j); break;
          case 3:deposer_objet(b.arme,j); break;
          case 4:deposer_objet(b.obj_construct,j); break;
          default:printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
     }      
}

void retirer_objet_banque(banque_t  b,joueur_t * j){
    liste_objet_t * pt=NULL;
    printf("De quel catégorie voulez-vous prendre votre objet?\n");
    printf("1 - Nourriture\n");
    printf("2 - Drogue\n");
    printf("3 - Arme\n");
    printf("4 - Objet de construction\n");
    scanf("%d",&choix);
    switch(choix){
          case 1:pt=b.nourriture; break;
          case 2:pt=b.drogue; break;
          case 3:pt=b.arme; break;
          case 4:pt=b.obj_construct; break;
          default:printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
    }
    if(pt!=NULL){
        prendre_objet(pt,j);
    }
}

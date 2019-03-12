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
            case 1: affiche_banque(l);
            case 2: ajouter_objet(l,j);
            case 3: retirer_objet(l,j);
            case 4:break;
            default: printf("Erreur, vous devez entrer un chiffre entre 1 et 4\n");
        }
    }while(choix!=4);
}




void affiche_banque(liste_objet_t * l){
    if(!liste_vide(l)){
        en_tete(l);


    }

}

void ajouter_objet(liste_objet_t * l,joueur_t * j){

}

void retirer_objet(liste_objet_t * l,joueur_t * j){

}

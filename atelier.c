#include "atelier.h"

void atelier(banque_t * banque, liste_objet_t * liste, joueur_t * joueur){
  int choix;
    do{
        printf("\nAtelier\n-------\nQue voulez-vous faire ?\n");
        printf("1 - Afficher les objets de l'inventaire\n");
        printf("2 - Faire une transformation\n");
        printf("3 - Quitter l'atelier\n");
        printf("Votre choix:");
        scanf("%d", &choix);

        switch(choix){
          case 1: printf("Objet transformable:\n"); objet_afficher_liste(banque->transformable); break;
          case 2: transformation(banque, liste, joueur); break;
          case 3: break;
          default: printf("Erreur, vous devez saisir un chiffre entre 1 et 3\n");
        }
      }while(choix!=3);
}

objet_t * trouver_objet_vfinal(liste_objet_t * liste, char * new){
  objet_t * obj_courant = malloc(sizeof(objet_t));
  objet_en_tete(liste);
  while(!objet_hors_liste(liste)){
    objet_valeur_elt(obj_courant, liste);
    if(strcmp(obj_courant->categorie, "materiau")){
      if(strcmp(obj_courant->attribut.new_nom, new)){
        return obj_courant;
      }
    }
    else{
      objet_suivant(liste);
    }
  }
  return NULL;
}

void transformation(banque_t * banque, liste_objet_t * liste, joueur_t * joueur){
  if(!objet_liste_vide(banque->transformable)){
    objet_t * pt;
    char * nom_objet;
    printf("Objet transformable:\n");
    objet_afficher_liste(banque->transformable);
    do{
      printf("Saisir l'objet à transformer:\n");
      scanf("%s",nom_objet);
    }while(objet_est_present(banque->transformable, nom_objet));
    pt=trouver_objet(banque->transformable, nom_objet);
    pt=trouver_objet_vfinal(liste, pt->nom_obj);
    objet_ajout_droit(*pt,banque->materiau);
    objet_supprimer(banque->transformable, nom_objet);
    printf("Objet transformable:\n");
    objet_afficher_liste(banque->transformable);
    printf("Matériau:\n");
    objet_afficher_liste(banque->materiau);
  }
}

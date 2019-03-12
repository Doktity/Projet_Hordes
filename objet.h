#include <stdio.h>
#include <stdlib.h>

#define TAILLE 100

typedef struct objet_s{
  char  nom_obj[TAILLE];
  char  categorie[TAILLE];
  char  description[TAILLE];
  int influ_pa;
}objet_t;

typedef struct liste_objet_s{
  objet_t val;
  struct liste_objet_s * pred;
  struct liste_objet_s * pred;
    struct liste_objet_s * ec;
  struct liste_objet_s * drapeau;
}liste_objet_t;

/**
*Primitives d'accès à la liste
*/
void init_liste(liste_objet_t*);

int liste_vide(liste_objet_t*);

int hors_liste(liste_objet_t*);

void en_tete(liste_objet_t*);

void en_queue(liste_objet_t*);

void precedent(liste_objet_t*);

void suivant(liste_objet_t*);

void valeur_elt(objet_t*,liste_objet_t*);

void modif_elt(objet_t,liste_objet_t*);

void oter_elt(liste_objet_t*);

void ajout_droit(objet_t,liste_objet_t*);

void ajout_gauche(objet_t,liste_objet_t*);

/**
* Cette fonction récupere les objets qui existe dans un fichier et les stockes dans un tableau
*/
void creer_liste(liste_objet_t *);

/**
* Affiche_liste affiche la liste complète des objets
* Pour chaque objet on indique son nom, sa catégorie, sa description et son influence sur les points d'actions
*/
void affiche_liste(liste_objet_t*);


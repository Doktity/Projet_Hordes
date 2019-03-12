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
}liste_objet_t;

/**
*Primitives d'accès à la liste
*/
void init_liste(void);

int liste_vide(void);

int hors_liste(void);

void en_tete(void);

void en_queue(void);

void precedent(void);

void suivant(void);

void valeur_elt(objet_t*);

void modif_elt(objet_t);

void oter_elt(void);

void ajout_droit(objet_t);

void ajout_gauche(objet_t);

/**
* Cette fonction récupere les objets qui existe dans un fichier et les stockes dans un tableau
*/
void creer_liste(void); 

void affiche_liste(void);

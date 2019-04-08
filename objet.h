#ifndef _OBJET_H_
#define _OBJET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 100

typedef struct objet_s{
  char  nom_obj[TAILLE];
  char  categorie[TAILLE];
  char  description[TAILLE];
  int attribut_obj;
  int id;
}objet_t;

typedef struct element_s{
  objet_t val;
  struct element_s * pred;
  struct element_s * succ;
}element_t;

typedef struct liste_objet_s{
  element_t * ec;
  element_t * drapeau;
}liste_objet_t;

/**
*Primitives d'accès à la liste
*/
void objet_init_liste(liste_objet_t**);

int objet_liste_vide(liste_objet_t*);

int objet_hors_liste(liste_objet_t*);

void objet_en_tete(liste_objet_t*);

void objet_en_queue(liste_objet_t*);

void objet_precedent(liste_objet_t*);

void objet_suivant(liste_objet_t*);

void objet_valeur_elt(objet_t*,liste_objet_t*);

void objet_modif_elt(objet_t,liste_objet_t*);

void objet_oter_elt(liste_objet_t*);

void objet_ajout_droit(objet_t,liste_objet_t*);

void objet_ajout_gauche(objet_t,liste_objet_t*);

/**
* Cette fonction récupere les objets qui existe dans un fichier et les stockes dans un tableau
*/
void objet_creer_liste(liste_objet_t **);

/**
* Affiche_liste affiche la liste complète des objets
* Pour chaque objet on indique son nom, sa catégorie, sa description et son influence sur les points d'actions
*/
void objet_afficher_liste(liste_objet_t*);

int est_present_objet(liste_objet_t *, char *);

objet_t * trouver_objet(liste_objet_t *, char *);

void supprimer_objet(liste_objet_t*,char *);

#endif

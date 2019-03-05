#include <stdio.h>
#include <stdlib.h>

#define nb_obj 20

typedef struct objet_s{
  char * nom_obj;
  char * categorie;
  char * description;
  int influ_pa;
}objet_t;

objet_t recup_fichier(); // Cette fonction récupere les objets qui existe dans un fichier et les stockes dans un tableau

objet_t tab_categorie(objet_t tab[],char * categorie);//Cette fonction retourne un tableau contenant les objets d'une catégorie

objet_t trouve_objet(objet_t * p,char * nom,char * categorie);//Cette fonction retourne un pointeur sur un objet selon son nom et sa catégorie

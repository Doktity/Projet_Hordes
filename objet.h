#include <stdio.h>
#include <stdlib.h>

#define nb_obj 20

typedef struct objet_s{
  char * nom_obj;
  char * categorie;
  char * description;
  int influ_pa;
}objet_t;

objet_t * recup_fichier(); // Cette fonction récupere les objets qui existe dans un fichier et les stockes dans un tableau

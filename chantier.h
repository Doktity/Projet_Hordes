#include "banque.h"

typedef struct structure_s{
  char nom[TAILLE];
  int defense; //nombre de défense que la structure générera
  int pa_requis; //Nombre de points d'actions pour pouvoir construire la structure, on décrémente au fur et à mesure qu'un joueur se dépense au chantier
  structure_t * structure_1; // Le premier structure requis pour pouvoir contruire la structure
  structure_t * structure_2;// Le second structure requis pour pouvoir construire la structure
  int nb_obj1;// Le nombre d'structures du type structure_1 nécessaire pour sa construction
  int nb_obj2;// Le nombre d'structures du type structure_2 nécessaire pour sa construction
  int construit;// défini si l'structure est déja construit ou non optionnel
}structure_t;

typedef struct partie_s{
  strucutre_t val;
  struct partie_s * pred;
  struct partie_s * succ;
}partie_t;

typedef struct liste_structure_s{
  partie_t * ec;
  partie_t * drapeau;
}liste_structure_t;


/**
*Primitives d'accès à la liste
*/
void structure_init_liste(liste_structure_t**);

int structure_liste_vide(liste_structure_t*);

int structure_hors_liste(liste_structure_t*);

void structure_en_tete(liste_structure_t*);

void structure_en_queue(liste_structure_t*);

void structure_precedent(liste_structure_t*);

void structure_suivant(liste_structure_t*);

void structure_valeur_elt(structure_t*,liste_structure_t*);

void structure_modif_elt(structure_t,liste_structure_t*);

void structure_oter_elt(liste_structure_t*);

void structure_ajout_droit(structure_t,liste_structure_t*);

void structure_ajout_gauche(structure_t,liste_structure_t*);

void chantier(liste_structure_t *, banque_t *, joueur_t *);

int joueur_travailler(joueur_t *, liste_structure_t *, banque_t *);

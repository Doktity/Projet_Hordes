#include "banque.h"

typedef struct defense_s{
  char nom[TAILLE];
  int defense; //nombre de défense que la defense générera
  int pa_requis; //Nombre de points d'actions pour pouvoir construire la defense, on décrémente au fur et à mesure qu'un joueur se dépense au chantier
  objet_t * objet_1; // Le premier objet requis pour pouvoir contruire la defense
  objet_t * objet_2;// Le second objet requis pour pouvoir construire la defense
  int nb_obj1;// Le nombre d'objet du type objet_1 nécessaire pour sa construction
  int nb_obj2;// Le nombre d'objet du type objet_2 nécessaire pour sa construction
  int construit;// défini si la defense est déja construite ou non optionnel
}defense_t;

typedef struct partie_s{
  defense_t val;
  struct partie_s * pred;
  struct partie_s * succ;
}partie_t;

typedef struct liste_defense_s{
  partie_t * ec;
  partie_t * drapeau;
}liste_defense_t;


/**
*Primitives d'accès à la liste
*/
void defense_init_liste(liste_defense_t**);

int defense_liste_vide(liste_defense_t*);

int defense_hors_liste(liste_defense_t*);

void defense_en_tete(liste_defense_t*);

void defense_en_queue(liste_defense_t*);

void defense_precedent(liste_defense_t*);

void defense_suivant(liste_defense_t*);

void defense_valeur_elt(defense_t*,liste_defense_t*);

void defense_modif_elt(defense_t,liste_defense_t*);

void defense_oter_elt(liste_defense_t*);

void defense_ajout_droit(defense_t,liste_defense_t*);

void defense_ajout_gauche(defense_t,liste_defense_t*);

void chantier(liste_defense_t *, banque_t *, joueur_t *);

void defense_afficher_liste(liste_defense_liste *);

int defense_dispo(defense_t,banque_t *);

int joueur_travailler(joueur_t *, liste_defense_t *, banque_t *);

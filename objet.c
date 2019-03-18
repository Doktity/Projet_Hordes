#include "objet.h"

void init_liste(liste_objet_t * liste){
  liste->drapeau=malloc(sizeof(element_t));
  liste->drapeau->pred=liste->drapeau;
  liste->drapeau->succ=liste->drapeau;
  liste->ec=liste->drapeau;
}

int liste_vide(liste_objet_t * liste){
  return (liste->drapeau->pred==liste->drapeau->succ);
}

int hors_liste(liste_objet_t * liste){
  return (liste->ec==liste->drapeau);
}

void en_tete(liste_objet_t * liste){
  if(!liste_vide(liste)){
    liste->ec=liste->drapeau->succ;
  }
}

void en_queue(liste_objet_t * liste){
  if(!liste_vide(liste)){
    liste->ec=liste->drapeau->pred;
  }
}

void suivant(liste_objet_t * liste){
  if(!hors_liste(liste)){
    liste->ec=liste->ec->succ;
  }
}

void precedent(liste_objet_t * liste){
  if(!hors_liste(liste)){
    liste->ec=liste->ec->pred;
  }
}

void valeur_elt(objet_t *v,liste_objet_t * liste){
  if(!hors_liste(liste)){
    *v= liste->ec->val;
  }
}

void modif_elt(objet_t v,liste_objet_t * liste){
  if(!hors_liste(liste)){
      liste->ec->val=v;
  }
}

void oter_elt(liste_objet_t * liste){
  if(!hors_liste(liste)){
		element_t * mem=malloc(sizeof(element_t));
		liste->ec->succ->pred=liste->ec->pred;
		liste->ec->pred->succ=liste->ec->succ;
		mem=liste->ec;
	  	liste->ec=liste->ec->succ;
		free(mem);
	  	mem=NULL;
	}
}

void ajout_droit(objet_t v,liste_objet_t * liste){
  if(liste_vide(liste)||!hors_liste(liste)){
		element_t * nouv;
		nouv=malloc(sizeof(element_t));
		nouv->val=v;
		nouv->pred=liste->ec;
		nouv->succ=liste->ec->succ;
		liste->ec->succ->pred=nouv;
		liste->ec->succ=nouv;
		liste->ec=nouv;
	}
}

void ajout_gauche(objet_t v,liste_objet_t * liste){
  if(liste_vide(liste)||!hors_liste(liste)){
    element_t * nouv;
    nouv=malloc(sizeof(element_t));
    nouv->val=v;
    nouv->pred=liste->ec;
    nouv->succ=liste->ec->pred;
    liste->ec->pred=nouv;
    liste->ec->succ=nouv;
    liste->ec=nouv;
  }
}

void creer_liste(liste_objet_t *liste){
  FILE * fic=fopen("liste_objet.txt","r");
  objet_t mem;
  char line[TAILLE];
  init_liste(liste);
  en_tete(liste);
  while(!feof(fic)){
    if((fgets(line, TAILLE, fic))!=NULL){
    	sscanf(line,"%s %s %i %[^\n]",mem.nom_obj,mem.categorie,&mem.influ_pa,mem.description);
    	ajout_droit(mem,liste);
    }	
  }
  fclose(fic);
}

void affiche_liste(liste_objet_t *liste){
  objet_t mem;
  if(!liste_vide(liste)){
    en_tete(liste);
    while(!hors_liste(liste)){
      valeur_elt(&mem,liste);
      printf("Nom:%s Catégorie:%s PA:%i \n",mem.nom_obj,mem.categorie,mem.influ_pa);
      printf("Description: %s\n",mem.description);
      printf("\n");
      suivant(liste);
    }
  }
}

#include <stdlib.h>
#include <string.h>
#include "objet.h"

void objet_init_liste(liste_objet_t ** new){
  (*new) = malloc(sizeof(liste_objet_t));
  (*new)->drapeau = malloc(sizeof(element_t));
  (*new)->drapeau->succ = (*new)->drapeau;
  (*new)->ec = (*new)->drapeau;
  (*new)->ec->pred=(*new)->drapeau;
}

int objet_liste_vide(liste_objet_t * liste){
  return (liste->drapeau->succ==liste->drapeau);
}

int objet_hors_liste(liste_objet_t * liste){
  return (liste->ec==liste->drapeau);
}

void objet_en_tete(liste_objet_t * liste){
  if(!objet_liste_vide(liste)){
    liste->ec=liste->drapeau->succ;
  }
}

void objet_en_queue(liste_objet_t * liste){
  if(!objet_liste_vide(liste)){
    liste->ec=liste->drapeau->pred;
  }
}

void objet_suivant(liste_objet_t * liste){
  if(!objet_hors_liste(liste)){
    liste->ec=liste->ec->succ;
  }
}

void objet_precedent(liste_objet_t * liste){
  if(!objet_hors_liste(liste)){
    liste->ec=liste->ec->pred;
  }
}

void objet_valeur_elt(objet_t *v,liste_objet_t * liste){
  if(!objet_hors_liste(liste)){
    *v= liste->ec->val;
  }
}

void objet_modif_elt(objet_t v,liste_objet_t * liste){
  if(!objet_hors_liste(liste)){
      liste->ec->val=v;
  }
}

void objet_oter_elt(liste_objet_t * liste){
  if(!objet_hors_liste(liste)){
		element_t * mem;
		liste->ec->succ->pred=liste->ec->pred;
		liste->ec->pred->succ=liste->ec->succ;
		mem=liste->ec;
	  liste->ec=liste->ec->succ;
		free(mem);
	  	mem=NULL;
	}
}

void objet_ajout_droit(objet_t v,liste_objet_t * liste){
  if(objet_liste_vide(liste)||!objet_hors_liste(liste)){
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

void objet_ajout_gauche(objet_t v,liste_objet_t * liste){
  if(objet_liste_vide(liste)||!objet_hors_liste(liste)){
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

void objet_creer_liste(liste_objet_t ** liste){
  FILE * fic=fopen("liste_objet.txt","r");
  objet_t mem;
  char line[TAILLE];
  objet_init_liste(liste);
  objet_en_tete(*liste);
  while(!feof(fic)){
    if((fgets(line, TAILLE, fic))!=NULL){
    	sscanf(line,"%s %s %i %[^\n]",mem.nom_obj,mem.categorie,&mem.attribut_obj,mem.description);
    	objet_ajout_droit(mem,*liste);
    }
  }
  fclose(fic);
}

void objet_afficher_liste(liste_objet_t *liste){
  objet_t mem;
  if(!objet_liste_vide(liste)){
    objet_en_tete(liste);
    while(!objet_hors_liste(liste)){
      objet_valeur_elt(&mem,liste);
      printf("Nom:%s Catégorie:%s PA:%i \n",mem.nom_obj,mem.categorie,mem.attribut_obj);
      printf("Description: %s\n",mem.description);
      printf("\n");
      objet_suivant(liste);
    }
  }
}


int objet_est_present(liste_objet_t * liste, char * nom){
  if(objet_liste_vide(liste)){
    return 0;
  }
  objet_t obj_courant;
  objet_en_tete(liste);
  while(!objet_hors_liste(liste)){
    objet_valeur_elt(&obj_courant,liste);
    if(strcmp(obj_courant.nom_obj,nom)){
      return 1;
    }
    objet_suivant(liste);
  }
  return 0;
}

objet_t * trouver_objet(liste_objet_t * liste, char * nom){
  char answer;
  objet_t * pt=NULL;
  if(objet_est_present(liste,nom)){
    objet_valeur_elt(pt,liste);
    return pt;
  }
  else{
    return NULL;
  }
}

void objet_supprimer(liste_objet_t * liste, char * nom){
  objet_t * sup=trouver_objet(liste,nom);
  if(sup!=NULL){
    objet_oter_elt(liste);
  }
}

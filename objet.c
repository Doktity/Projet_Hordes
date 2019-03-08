#include "objet.h"

liste_objet_t * ec; //L'élement courant de la liste
liste_objet_t * drapeau;

void init_liste(void){
  drapeau=malloc(sizeof(objet_t));
  drapeau->pred=drapeau;
  drapeau->succ=drapeau;
  ec=drapeau;
}

int liste_vide(void){
  return (drapeau->pred==drapeau->succ);
}

int hors_liste(void){
  return (ec==drapeau);
}

void en_tete(void){
  if(!liste_vide()){
    ec=drapeau->succ;
  }
}

void en_queue(void){
  if(!liste_vide()){
    ec=drapeau->pred;
  }
}

void suivant(void){
  if(!hors_liste()){
    ec=ec->succ;
  }
}

void precedent(void){
  if(!hors_liste()){
    ec=ec->pred;
  }
}

void valeur_elt(objet_t *v){
  if(!hors_liste()){
    *v= ec->val;
  }
}

void modif_elt(objet_t v){
  if(!hors_liste()){
      ec->val=v;
  }
}

void oter_elt(void){
	if(!hors_liste()){
		liste_objet_t * mem;
		ec->succ->pred=ec->pred;
		ec->pred->succ=ec->succ;
		mem=ec->succ;
		free(ec);
		ec->pred=mem;
		mem->succ=ec;
	}
}

void ajout_droit(objet_t v){
	if(liste_vide()||!hors_liste()){
		liste_objet_t * nouv;
		nouv=malloc(sizeof(liste_objet_t));
		nouv->val=v;
		nouv->pred=ec;
		nouv->succ=ec->succ;
		ec->succ->pred=nouv;
		ec->succ=nouv;
		ec=nouv;
	}
}

void ajout_gauche(objet_t v){
	  if(liste_vide()||!hors_liste()){
    liste_objet_t * nouv;
    nouv=malloc(sizeof(liste_objet_t));
    nouv->val=v;
    nouv->pred=ec;
    nouv->succ=ec->pred;
    ec->pred=nouv;
    ec->succ=nouv;
    ec=nouv;
  }
}

objet_t * recup_fichier(){
	FILE * fic=NULL;
	objet_t mem;
	init_liste();
	en_tete();
	int i=0;
	if(fopen("liste_objet.txt","r")==NULL){ //Test pour savoir si le fichier est présent
		printf("Erreur lors de l'ouverture du fichier liste_objet\n");
		return;
	}
	else fic=fopen("liste_objet.txt","r");
	fscanf(fic,"%s:%s:%[^\n]:%i",mem.nom_obj,mem.nom_obj,mem.description,&mem.influ_pa);
	ajou_droit(mem);
	while(!feof(fic)){
		i++;
		fscanf(fic,"%s:%s:%[^\n]:%i",mem.nom_obj,mem.nom_obj,mem.description,&mem.influ_pa);
		ajout_droit(mem);
	}
	fclose(fic);
}

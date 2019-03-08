#include "objet.h"

objet_t * ec; //L'élement courant de la liste
objet_t * drapeau;

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
      ec->valeur=v;
  }
}

void oter_elt(void){

}

void ajout_droit(objet_t v){

}

void ajout_gauche(objet_t v){

}

objet_t * recup_fichier(){
	FILE * fic=NULL;
	objet_t tab[nb_obj]; //Tableau qui stockera les valeurs contenues dans le fichier
	int i=0;
	if(fopen("liste_objet.txt","r")==NULL){ //Test pour savoir si le fichier est présent
		printf("Erreur lors de l'ouverture du fichier liste_objet\n");
		return 0;
	}
	else fic=fopen("liste_objet.txt","r");
	fscanf(fic,"%s:%s:%s:%i",tab[i]->nom_obj,tab[i]->categorie,tab[i]->description,&tab[i]->influ_pa);
	while(!feof(fic)){
		i++;
		fscanf(fic,"%s:%s:%s:%i",tab[i]->nom_obj,tab[i]->categorie,tab[i]->description,&tab[i]->influ_pa);
	}
	fclose(fic);
	return *tab;
}

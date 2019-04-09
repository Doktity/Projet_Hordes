#include "liste_joueur.h"

void joueur_init_liste(void){
	drapeau = malloc(sizeof(elt_joueur_t));
	drapeau->pred = drapeau;
	drapeau->succ = drapeau;
	ec = drapeau;
}

int joueur_liste_vide(void){
	return (drapeau->succ==drapeau);
}

int joueur_hors_liste(void){
	return (ec==drapeau);
}

void joueur_en_tete(void){
	if(!joueur_liste_vide()) ec = drapeau->succ;
}

void joueur_en_queue(void){
	if(!joueur_liste_vide()) ec = drapeau->pred;
}

void joueur_suivant(void){
	if(!joueur_hors_liste()){
		ec = ec->succ;
	}
}

void joueur_precedent(void){
	if(!joueur_hors_liste()){
		ec = ec->pred;
	}
}

void joueur_valeur_elt(joueur_t ** j){
	if(!joueur_hors_liste()){
		*j = ec->valeur;
	}
}

void joueur_modif_elt(joueur_t * j){
	if(!joueur_hors_liste()){
		ec->valeur = j;
	}
}

void joueur_oter_elt(void){
  if(!joueur_hors_liste()){
		elt_joueur_t * mem;
		ec->succ->pred = ec->pred;
		ec->pred->succ = ec->succ;
		mem = ec;
	  	ec = ec->succ;
		free(mem);
	  	mem=NULL;
	}
}

void joueur_ajout_droit(joueur_t * j){
	if(joueur_liste_vide()||!joueur_hors_liste()){
		elt_joueur_t * nouv;
		nouv = malloc(sizeof(elt_joueur_t));
		nouv->valeur = j;
		nouv->pred = ec;
		nouv->succ = ec->succ;
		ec->succ->pred = nouv;
		ec->succ = nouv;
		ec = nouv;
	}
}

void joueur_ajout_gauche(joueur_t * j){
	if(joueur_liste_vide()||!joueur_hors_liste()){
		elt_joueur_t * nouv;
		nouv = malloc(sizeof(elt_joueur_t));
		nouv->valeur = j;
		nouv->pred = ec;
		nouv->succ = ec->pred;
		ec->pred = nouv;
		ec->succ = nouv;
		ec = nouv;
	}
}

void joueur_afficher_liste(void){
	joueur_t * mem;
	if(!joueur_liste_vide()){
		joueur_en_tete();
		while(!joueur_hors_liste()){
			joueur_valeur_elt(&mem);
			printf("Nom : %s, Position : %d-%d, pa : %d\n",mem->nom, mem->posx, mem->posy, mem->pa);
			afficher_inventaire(mem);
			joueur_suivant();
		}
	}
}

joueur_t * joueur_trouver(char * nom){
	joueur_t * mem;
	if(!joueur_liste_vide())
	{
		joueur_en_tete();
		do
		{
			joueur_valeur_elt(&mem);
			if(strcmp(mem->nom, nom) != 0){
				joueur_suivant();
			}
		}
		while(!joueur_hors_liste() && strcmp(mem->nom, nom) != 0);
		if(strcmp(mem->nom, nom) == 0)
		{
			return mem;
		}
		else
		{
			return NULL;
		}
	}
}

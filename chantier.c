#include "chantier.h"

void structure_init_liste(liste_structure_t ** new){
	(*new) = malloc(sizeof(liste_structure_t));
	(*new)->drapeau = malloc(sizeof(partie_t));
	(*new)->drapeau->succ = (*new)->drapeau;
	(*new)->ec = (*new)->drapeau;
	(*new)->ec->pred = (*new)->drapeau;
}

int structure_liste_vide(liste_structure_t * liste){
	return (liste->drapeau->succ == liste->drapeau);
}

int structure_hors_liste(liste_structure_t * liste){
	return (liste->ec == liste->drapeau);
}

void structure_en_tete(liste_structure_t * liste){
	if(!structure_liste_vide(liste)){
   		liste->ec = liste->drapeau->succ;
 	}
}

void structure_en_queue(liste_structure_t * liste){
	if(!sstructure_liste_vide(liste)){
		liste->ec = liste->drapeau->pred; 
	}

}

void structure_suivant(liste_structure_t * liste){
	if(!structure_hors_liste(liste)){
		liste->ec = liste->drapeau->succ;
	}
}

void structure_precedent(liste_structure_t * liste){
	if(!structure_hors_liste(liste)){
   		liste->ec = liste->drapeau->pred;
 	}
}

void structure_valeur_elt(structure_t*, liste_structure_t*){
	if(!objet_hors_liste(liste)){
    	*v = liste->ec->val;
 	}
}

void structure_modif_elt(structure_t v, liste_structure_t * liste){
	if(!structure_hors_liste(liste)){
		liste->ec->val = v;
	}
}

void structure_oter_elt(liste_structure_t * liste){
	if(!structure_hors_liste(liste)){
		partie_t * mem;
		liste->ec->succ->pred = liste->ec->pred;
		liste->ec->pred->succ = liste->ec->succ;
		mem = liste->ec;
		liste->ec = liste->ec->succ;
		free(mem);
		mem=NULL;
	}
}

void structure_ajout_droit(structure_t v, liste_structure_t * liste){
	if(structure_liste_vide(liste)||!structure_hors_liste(liste)){
		partie_t * nouv;
		nouv = malloc(sizeof(partie_t));
		nouv->val = v;
		nouv->pred = liste->ec;
		nouv->succ = liste->ec->succ;
		liste->ec->succ->pred = nouv;
		liste->ec->succ = nouv;
		liste->ec = nouv;
	}
}

void structure_ajout_gauche(structure_t v, liste_structure_t * liste){
	if(structure_liste_vide(liste) || !structure_hors_liste(liste)){
	    element_t * nouv;
	    nouv = malloc(sizeof(partie_t));
	    nouv->val = v;
	    nouv->pred = liste->ec;
	    nouv->succ = liste->ec->pred;
	    liste->ec->pred = nouv;
	    liste->ec->succ = nouv;
	    liste->ec = nouv;
   }
}

void structure_creer_liste(liste_structure_t ** liste){
	FILE * fic = = fopen("liste_structure.txt", "r");
	structure_t mem;
	char line[TAILLE];
	structure_init_liste(liste);
	structure_en_tete(*liste);
	while(!feof(fic)){
		if((fgets(line, TAILLE, fic)) != NULL){
			sscanf(line, "%s %i %i  %s %s %i %i %i",mem.nom, &mem.defense, &mem.pa_requis, mem.structure_1, mem.structure2, &mem.nb_obj1, &mem.nb_obj2, &mem.construit);
			structure_ajout_droit(mem, *liste);
		}
	}
	fclose(fic);
}


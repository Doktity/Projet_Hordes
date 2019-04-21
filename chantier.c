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

void structure_afficher_liste(liste_structure_t *){
	structure_t mem;
  if(!structure_liste_vide(liste)){
    structure_en_tete(liste);
    while(!structure_hors_liste(liste)){
      structure_valeur_elt(&mem,liste);
      printf("Nom:%s pa_requis:%i objet1:%s nb_obj:%i objet2:%s nb_obj:%i\n", mem.nom, mem.defense, mem.pa_requis, mem->structure_1.nom_obj, mem.nb_obj1, mem->structure_2.nom_obj, mem.nb_obj2);
      printf("\n");
      structure_suivant(liste);
    }
  }
}

int structure_dispo(stucture_t struct, banque_t * banque){
	objet_t num1,num2;
	return 0
}

void chantier(liste_structure_t * liste, banque_t * banque, joueur_t joueur){
	int choix;
    do{
        printf("\nChantier\n-------\nQue voulez-vous faire ?\n");
        printf("1 - Afficher les structures disponibles\n");
        printf("2 - Construire une structure\n");
        printf("3 - Quitter le chantier\n");
        printf("Votre choix:");
        scanf("%d", &choix);

        switch(choix){
          case 1: structure_afficher_liste(liste); break;
          case 2: joueur->pa=joueur_travailler(joueur, liste, banque); break;
          case 3: break;
          default: printf("Erreur, vous devez saisir un chiffre entre 1 et 3\n");
        }
      }while(choix!=3);
}
#include "chantier.h"

void defense_init_liste(liste_defense_t ** new){
	(*new) = malloc(sizeof(liste_defense_t));
	(*new)->drapeau = malloc(sizeof(partie_t));
	(*new)->drapeau->succ = (*new)->drapeau;
	(*new)->ec = (*new)->drapeau;
	(*new)->ec->pred = (*new)->drapeau;
}

int defense_liste_vide(liste_defense_t * liste){
	return (liste->drapeau->succ == liste->drapeau);
}

int defense_hors_liste(liste_defense_t * liste){
	return (liste->ec == liste->drapeau);
}

void defense_en_tete(liste_defense_t * liste){
	if(!defense_liste_vide(liste)){
   		liste->ec = liste->drapeau->succ;
 	}
}

void defense_en_queue(liste_defense_t * liste){
	if(!defense_liste_vide(liste)){
		liste->ec = liste->drapeau->pred;
	}

}

void defense_suivant(liste_defense_t * liste){
	if(!defense_hors_liste(liste)){
		liste->ec = liste->drapeau->succ;
	}
}

void defense_precedent(liste_defense_t * liste){
	if(!defense_hors_liste(liste)){
   		liste->ec = liste->drapeau->pred;
 	}
}

void defense_valeur_elt(defense_t * v, liste_defense_t * liste){
	if(!objet_hors_liste(liste)){
    	*v = liste->ec->val;
 	}
}

void defense_modif_elt(defense_t v, liste_defense_t * liste){
	if(!defense_hors_liste(liste)){
		liste->ec->val = v;
	}
}

void defense_oter_elt(liste_defense_t * liste){
	if(!defense_hors_liste(liste)){
		partie_t * mem;
		liste->ec->succ->pred = liste->ec->pred;
		liste->ec->pred->succ = liste->ec->succ;
		mem = liste->ec;
		liste->ec = liste->ec->succ;
		free(mem);
		mem=NULL;
	}
}

void defense_ajout_droit(defense_t v, liste_defense_t * liste){
	if(defense_liste_vide(liste)||!defense_hors_liste(liste)){
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

void defense_ajout_gauche(defense_t v, liste_defense_t * liste){
	if(defense_liste_vide(liste) || !defense_hors_liste(liste)){
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

void defense_creer_liste(liste_defense_t ** liste){
	FILE * fic = = fopen("liste_defense.txt", "r");
	defense_t mem;
	char line[TAILLE];
	defense_init_liste(liste);
	defense_en_tete(*liste);
	while(!feof(fic)){
		if((fgets(line, TAILLE, fic)) != NULL){
			sscanf(line, "%s %i %i  %s %s %i %i %i",mem.nom, &mem.val, &mem.pa_requis, mem.objet_1, mem.objet_2, &mem.nb_obj1, &mem.nb_obj2, &mem.construit);
			defense_ajout_droit(mem, *liste);
		}
	}
	fclose(fic);
}

void defense_afficher_liste(liste_defense_t *){
	defense_t mem;
  if(!defense_liste_vide(liste)){
    defense_en_tete(liste);
    while(!defense_hors_liste(liste)){
      defense_valeur_elt(&mem,liste);
      printf("Nom:%s pa_requis:%i objet1:%s nb_obj:%i objet2:%s nb_obj:%i\n", mem.nom, mem.val, mem.pa_requis, mem->objet_1.nom_obj, mem.nb_obj1, mem->objet_2.nom_obj, mem.nb_obj2);
      printf("\n");
      defense_suivant(liste);
    }
  }
}

int defense_dispo(defense_t struct, banque_t * banque){
	objet_t num1,num2;
	return 0
}

void chantier(liste_defense_t * liste, banque_t * banque, joueur_t joueur){
	int choix;
    do{
        printf("\nChantier\n-------\nQue voulez-vous faire ?\n");
        printf("1 - Afficher les defenses disponibles\n");
        printf("2 - Construire une defense\n");
        printf("3 - Quitter le chantier\n");
        printf("Votre choix:");
        scanf("%d", &choix);

        switch(choix){
          case 1: defense_afficher_liste(liste); break;
          case 2: joueur->pa=joueur_travailler(joueur, liste, banque); break;
          case 3: break;
          default: printf("Erreur, vous devez saisir un chiffre entre 1 et 3\n");
        }
      }while(choix!=3);
}

#include "objet.h"

objet_t recup_fichier(){
  FILE * fic=NULL;
	objet_t tab[nb_obj]; //Tableau qui stockera les valeurs contenues dans le fichier
	int i=0;
	if(fopen("liste_objet.txt","r")==NULL){ //Test pour savoir si le fichier est présent
		printf("Erreur lors de l'ouverture du fichier liste_objet\n");
		return NULL;
	}
	else fic=fopen("liste_objet.txt","r");
	fscanf(fic,"%s:%s:%s:%i",&tab[i].nom_obj,&tab[i].categorie,&tab[i].description,&tab[i].influ_pa);
	while(!feof(fic)){
		i++;
		fscanf(fic,"%s:%s:%s:%i",&tab[i].nom_obj,&tab[i].categorie,&tab[i].description,&tab[i].influ_pa);
	}
	fclose(fic);
	return tab;
}

objet_t tab_categorie(objet_t tab[],char * categorie){
	objet_t cat_tab[nb_obj];
	int i,j=0;
	for(i=0;i<nb_obj;i++){//On parcours le tableau à la recherche des objets portant le nom de la catégorie recherché
		if(tab[i].categorie==categorie){
			cat_tab[j]=tab[i];
			j++;
		}
	}
	return cat_tab;
}

objet_t trouve_objet(objet_t * p,char * nom,char * categorie){

}

int main(){

  return 0;
}

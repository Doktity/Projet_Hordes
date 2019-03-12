#include "main.h"

void *thread_1(void *arg)

{
  time_t depart;
  tour_t tour;
  tour.nb_tour = 1;
  int nb_t = 0;
  depart = time(NULL);

  while(tour.nb_tour < 10){
        tour.temps = time(NULL);
        if((tour.temps - depart) >= DIX){
          depart += DIX;
          tour.nb_tour++;
        }
        if(nb_t != tour.nb_tour){
          printf("%d tours.\n", tour.nb_tour);
          nb_t = tour.nb_tour;
        }
  }

  (void) arg;

  pthread_exit(NULL);

}


int main(){

  t_mat * carte = creer_carte();

  joueur_t * joueur;
  char nom[20];
  objet_t inventaire[4];
  int statut[] = {0,0,0,0,1,0,0};

  pthread_t thread1;

  int choix;

  printf("Nom : ");
  scanf("%s", nom);

  joueur = Creer_Joueur(nom, 6, inventaire, statut);

  printf("Bonjour %s !\n", joueur->nom);

  if(pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
  	perror("pthread_create");
  	return EXIT_FAILURE;
  }

  do
/* Affichage du menu et saisie du choix */
	{	printf("\nMenu :\n");
		printf(" 1 - Maison\n");
		printf(" 2 - Puit\n");
		printf(" 3 - Banque\n");
		printf(" 4 - Citoyen\n");
		printf(" 5 - Chantier\n");
		printf(" 6 - Atelier\n");
    printf(" 7 - Forum\n");
    printf(" 8 - Grande Porte\n");
    printf(" 9 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: printf("coucou"); //maison(); break;
			case 2: printf("coucou"); //puit(); break;
			case 3: printf("coucou"); //banque(); break;
			case 4: printf("coucou"); //citoyen(); break;
			case 5: printf("coucou"); //chantier(); break;
			case 6: printf("coucou"); //atelier(); break;
      case 7: printf("coucou"); //forum(); break;
      case 8: afficher_carte(carte); //porte(); break;
      case 9: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 9\n");
		}
	}
	while(choix!=9);

  return 0;

}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#include "main.h"

t_mat * carte;

int attaque(int nb_tour, int nb_joueur, int puissance)
/* Fonction pour déterminer la puissance des zombies lors de l'attaque */
{
  float f_tour = (float)(nb_tour) / 10;
  float f_joueur = (float)(nb_joueur) / 10;

  puissance = puissance + rand() % NB_ZOMBIE_MAX * f_tour * f_joueur + NB_ZOMBIE_MIN;

  return puissance;
}


void *thread_1(void *arg)
/* Fonction thread pour gérer la gestion des tours de jeu hors du processus principal*/
{
  time_t depart;
  tour_t tour;
  tour.nb_tour = 1;
  int nb_t = 0;
  int nb_zombie_hier = 1;
  depart = time(NULL);

  int puissance = 0;

  while(!joueur_liste_vide()){
        tour.temps = time(NULL);
        if((tour.temps - depart) >= DIX){
          depart += DIX;
          tour.nb_tour++;
        }
        if(nb_t != tour.nb_tour){
          puissance = attaque(tour.nb_tour, 5, puissance);
          printf("\n%d tours - puissance des zombies : %d\n", tour.nb_tour, puissance);
          nb_zombie_hier = calculer_pos_zombie(carte, tour.nb_tour, nb_zombie_hier);
          printf("%d\n", nb_zombie_hier);
          nb_t = tour.nb_tour;
        }
  }

  (void) arg;

  pthread_exit(NULL);

}


int main()
{

  srand(time(NULL));

  carte = creer_carte();

  joueur_t * joueur;
  char nom[100];

  joueur_init_liste();

  liste_objet_t * liste;
  objet_creer_liste(&liste);

	banque_t * liste_banque = malloc(sizeof(banque_t));
  init_banque(liste_banque);

  pthread_t thread1;

  int choix;

  int ration = 150;

	system("clear");

  printf("Nom : ");
  scanf("%s", nom);

  joueur = creer_joueur(nom);
  carte->mat[6][6].nb_joueur++;
  joueur_ajout_droit(joueur);
 

  printf("Bonjour %s !\n", joueur->nom);

  if(pthread_create(&thread1, NULL, thread_1, NULL) == -1) {
  	perror("pthread_create");
  	return EXIT_FAILURE;
  }

  do
/* Affichage du menu et saisie du choix */
  {
		printf("\nMenu :\n");
		printf(" 1 - Maison\n");
		printf(" 2 - Puit\n");
		printf(" 3 - Banque\n");
		printf(" 4 - Citoyen\n");
		printf(" 5 - Chantier\n");
		printf(" 6 - Atelier\n");
		printf(" 7 - Grande Porte\n");
		printf(" 8 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: maison(joueur);
              break;
			case 2: puit(&ration, joueur, liste);
              break;
			case 3: banque(liste_banque, joueur);
              break;
			case 4: system("clear");
              joueur_afficher_liste();
              break;
			case 5: printf("coucou"); //chantier(); break;
			case 6: atelier(liste_banque, liste, joueur); break;
      case 7: action_carte(joueur, carte);
              break;
      case 8: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 8\n");
		}
	}
	while(choix!=8);

  liberer_matrice(carte);

  return 0;

}

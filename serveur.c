#include "serveur.h"

void fin(int sig){
	printf("fin du serveur");
}

int hostname_to_ip(char * hostname , char* ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
         
    if ( (he = gethostbyname( hostname ) ) == NULL) 
    {
        // get the host info
        herror("gethostbyname");
        return 1;
    }
 
    addr_list = (struct in_addr **) he->h_addr_list;
     
    for(i = 0; addr_list[i] != NULL; i++) 
    {
        //Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;
    }
     
    return 1;
}


void view_ip()
{
  char s[256];
  struct hostent *host;
  struct in_addr **adr;
  if (!gethostname(s, 256))
    if ((host = gethostbyname(s)) != NULL)
      for (adr = (struct in_addr **)host->h_addr_list; *adr; adr++)
          printf("IP : %s\n", inet_ntoa(**adr));
}


int attaque(int nb_tour, int nb_joueur, int puissance)
/* Fonction pour déterminer la puissance des zombies lors de l'attaque */
{
  float f_tour = (float)(nb_tour) / 10;
  float f_joueur = (float)(nb_joueur) / 10;

  puissance = puissance + rand() % NB_ZOMBIE_MAX * f_tour * f_joueur + NB_ZOMBIE_MIN;

  return puissance;
}

int main ( void )
{
    srand(time(NULL));

	int ma_socket;
	int client_socket;
	struct sockaddr_in mon_address, client_address;
	unsigned int mon_address_longueur, lg;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(30000);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	char *hostname = "localhost";
    char ip[100];
     
    hostname_to_ip(hostname , ip);
	fprintf(stderr, "%s resolved to %s" , hostname , ip);
	view_ip();

	/* creation de socket */
	if ((ma_socket = socket(AF_INET,SOCK_STREAM,0))== -1) {
		printf("Impossible de créer la socket\n");
		exit(0);
	}

	/* bind serveur - socket */
	bind(ma_socket,(struct sockaddr *)&mon_address,sizeof(mon_address));
	/* ecoute sur la socket */
	listen(ma_socket,5);
	/* accept la connexion */
	mon_address_longueur = sizeof(client_address);
	
    /* on attend que le client se connecte */
	client_socket = accept(ma_socket,
                         (struct sockaddr *)&client_address,
                         &mon_address_longueur);
    
    t_mat * carte = creer_carte();
    time_t depart;
    tour_t tour;
    tour.nb_tour = 1;
    int nb_t = 0;
    int nb_zombie_hier = 1;
    depart = time(NULL);
    int puissance = 0;

    joueur_t * joueur;
    joueur_init_liste();
    char * menu1;
    char * nom;

    while(joueur_liste_vide()){
        memset(buffer, 0, sizeof(buffer));
		lg = recv(client_socket, buffer, 512,0);

        if(strncmp("BONJOUR", buffer, strlen("BONJOUR")) == 0)
        {
			printf("[serveur] BONJOUR de %s\n", buffer + strlen("BONJOUR") + 1);
            joueur = creer_joueur(buffer + strlen("BONJOUR") + 1);
            carte->mat[6][6].nb_joueur++;
            joueur_ajout_droit(joueur);
			send(client_socket, buffer, 512, 0);
        }
    }

    while(!joueur_liste_vide()){

        memset(buffer, 0, sizeof(buffer));
        memset(menu1, 0, sizeof(menu1));
		lg = recv(client_socket, buffer, 512,0);

        tour.temps = time(NULL);
        if((tour.temps - depart) >= DIX){
            depart += DIX;
            tour.nb_tour++;
        }
        if(nb_t != tour.nb_tour){
            puissance = attaque(tour.nb_tour, 5, puissance);
            printf("\n%d tours - puissance des zombies : %d\n", tour.nb_tour, puissance);
            nb_zombie_hier = calculer_pos_zombie(carte, tour.nb_tour, nb_zombie_hier);
            nb_t = tour.nb_tour;
        }

        
        if(strncmp("MAISON", buffer, strlen("MAISON")) == 0)
        {
			printf("[serveur] message reçu : '%s'\n", buffer + strlen("MAISON") + 1);
			printf("[serveur] envoi de la réponse ");
            menu1 = buffer + strlen("MAISON") + 1;
            if(strncmp("ameliorer", menu1, strlen("ameliorer")) == 0)
            {
                nom = menu1 + strlen("ameliorer") + 1;
                sprintf(buffer, "%s veut améliorer sa maison", nom);
            }
            else if(strncmp("afficher", menu1, strlen("afficher")) == 0)
            {
                nom = menu1 + strlen("afficher") + 1;
                sprintf(buffer, "%s veut afficher l'inventaire du coffre", nom);
            }
            else if(strncmp("utiliser", menu1, strlen("utiliser")) == 0)
            {
                nom = menu1 + strlen("utiliser") + 1;
                sprintf(buffer, "%s veut utiliser l'inventaire", nom);
            }
            else if(strncmp("deposer", menu1, strlen("deposer")) == 0)
            {
                nom = menu1 + strlen("deposer") + 1;
                sprintf(buffer, "%s veut deposer son inventaire dans le coffre", nom);
            }
            else if(strncmp("prendre", menu1, strlen("prendre")) == 0)
            {
                nom = menu1 + strlen("prendre") + 1;
                sprintf(buffer, "%s veut prendre un objet du coffre", nom);
            }
			send(client_socket, buffer, 512, 0);
		}
        else if(strncmp("PUIT", buffer, strlen("PUIT")) == 0)
        {
            printf("[serveur] message reçu : '%s'\n", buffer + strlen("PUIT") + 1);
			printf("[serveur] envoi de la réponse ");
            menu1 = buffer + strlen("PUIT") + 1;
            if(strncmp("prendre", menu1, strlen("prendre")) == 0)
            {
                nom = menu1 + strlen("prendre") + 1;
                sprintf(buffer, "%s veut prendre de l'eau", nom);
            }
            else if(strncmp("ajouter", menu1, strlen("ajouter")) == 0)
            {
                nom = menu1 + strlen("ajouter") + 1;
                sprintf(buffer, "%s veut ajouter de l'eau", nom);
            }
			send(client_socket, buffer, 512, 0);
        }
        else if(strncmp("BANQUE", buffer, strlen("BANQUE")) == 0)
        {
            printf("[serveur] message reçu : '%s'\n", buffer + strlen("BANQUE") + 1);
			printf("[serveur] envoi de la réponse ");
            menu1 = buffer + strlen("BANQUE") + 1;
            if(strncmp("afficher", menu1, strlen("afficher")) == 0)
            {
                nom = menu1 + strlen("prendre") + 1;
                sprintf(buffer, "%s veut afficher la banque", nom);
            }
            else if(strncmp("ajouter", menu1, strlen("ajouter")) == 0)
            {
                nom = menu1 + strlen("ajouter") + 1;
                sprintf(buffer, "%s veut ajouter un objet à la banque", nom);
            }
            else if(strncmp("prendre", menu1, strlen("prendre")) == 0)
            {
                nom = menu1 + strlen("prendre") + 1;
                sprintf(buffer, "%s veut prendre un objet à la banque", nom);
            }
			send(client_socket, buffer, 512, 0);
        }
        else if(strncmp("PORTE", buffer, strlen("PORTE")) == 0)
        {
            printf("[serveur] message reçu : '%s'\n", buffer + strlen("PORTE") + 1);
			printf("[serveur] envoi de la réponse ");
            menu1 = buffer + strlen("PORTE") + 1;
            if(strncmp("gauche", menu1, strlen("gauche")) == 0)
            {
                nom = menu1 + strlen("gauche") + 1;
                sprintf(buffer, "%s veut se déplacer à gauche", nom);
            }
            else if(strncmp("droite", menu1, strlen("droite")) == 0)
            {
                nom = menu1 + strlen("droite") + 1;
                sprintf(buffer, "%s veut se déplacer à droite", nom);
            }
            else if(strncmp("haut", menu1, strlen("haut")) == 0)
            {
                nom = menu1 + strlen("haut") + 1;
                sprintf(buffer, "%s veut se déplacer en haut", nom);
            }
            else if(strncmp("bas", menu1, strlen("bas")) == 0)
            {
                nom = menu1 + strlen("bas") + 1;
                sprintf(buffer, "%s veut se déplacer en bas", nom);
            }
            else if(strncmp("fouiller", menu1, strlen("fouiller")) == 0)
            {
                nom = menu1 + strlen("fouiller") + 1;
                sprintf(buffer, "%s veut fouiller l'endroit", nom);
            }
            else if(strncmp("attaquer", menu1, strlen("attaquer")) == 0)
            {
                nom = menu1 + strlen("attaquer") + 1;
                sprintf(buffer, "%s veut attaquer un zombie", nom);
            }
            else if(strncmp("prendre", menu1, strlen("prendre")) == 0)
            {
                nom = menu1 + strlen("prendre") + 1;
                sprintf(buffer, "%s veut prendre un objet", nom);
            }
            else if(strncmp("afficher", menu1, strlen("afficher")) == 0)
            {
                nom = menu1 + strlen("gauche") + 1;
                sprintf(buffer, "%s veut afficher la carte", nom);
            }
			send(client_socket, buffer, 512, 0);
        }
        else if(strncmp("QUITTER", buffer, 7) == 0)
        {
			printf("[serveur] déconnexion demandée : '%s'\n",buffer);
			shutdown(client_socket,2);
			close(client_socket);
		}
    }

    liberer_matrice(carte);
	shutdown(ma_socket,2);
	close(ma_socket);
	return 0;
}

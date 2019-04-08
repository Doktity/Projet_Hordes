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

	int ma_socket, i = 0/*, nouv_client*/;
	int client_socket/*[TAILLE_MAX]*/;
	struct sockaddr_in mon_address, client_address;
	unsigned int mon_address_longueur, lg;
	bzero(&mon_address,sizeof(mon_address));
	mon_address.sin_port = htons(30000);
	mon_address.sin_family = AF_INET;
	mon_address.sin_addr.s_addr = htonl(INADDR_ANY);

	char *hostname = "localhost";
    char ip[100];

    t_mat * carte = creer_carte();
    time_t depart;
    tour_t tour;
    tour.nb_tour = 1;
    int nb_t = 0;
    int nb_zombie_hier = 1;
    depart = time(NULL);
    int puissance = 0;

    liste_objet_t * liste;
    objet_creer_liste(&liste);

	banque_t * liste_banque = malloc(sizeof(banque_t));
    init_banque(liste_banque);

    int ration = 150;

    joueur_t * joueur;
    joueur_init_liste();
    char * choix = malloc(sizeof(char));
    char * nom = malloc(sizeof(char));
    char * batiment = malloc(sizeof(char));
    char * mem = malloc(sizeof(char));
    char * delim = " ";
     
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
	client_socket/*[i]*/ = accept(ma_socket,
                         (struct sockaddr *)&client_address,
                         &mon_address_longueur);

    /* On attend le nom du premier joueur */
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

    /* Boucle principale */
    while(!joueur_liste_vide()){

        /*nouv_client = accept(ma_socket,
                        (struct sockaddr *)&client_address),
                        &mon_address_longueur,
                        O_NON_BLOCK);*/

        memset(buffer, 0, sizeof(buffer));
		lg = recv(client_socket, buffer, 512, MSG_DONTWAIT);

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

        if(strncmp("BONJOUR", buffer, strlen("BONJOUR")) == 0)
        {
            printf("[serveur] BONJOUR de %s\n", buffer + strlen("BONJOUR") + 1);
            joueur = creer_joueur(buffer + strlen("BONJOUR") + 1);
            carte->mat[6][6].nb_joueur++;
            joueur_ajout_droit(joueur);
            send(client_socket, buffer, 512, 0);
        }
        else if(strncmp("MSG", buffer, strlen("MSG")) == 0)
        {
            strcpy(mem, buffer + strlen("MSG") + 1);
            mem = strtok(mem, delim);
            sprintf(batiment, "%s", mem);
            mem = strtok(NULL, delim);
            sprintf(nom, "%s", mem);
            mem = strtok(NULL, delim);
            sprintf(choix, "%s", mem);
            
            printf("[serveur] envoi de la réponse ");
            joueur = joueur_trouver(nom);

            if(strncmp("MAISON", batiment, strlen("MAISON")) == 0)
            {
                maison(atoi(choix), joueur);
            }
            else if(strncmp("PUIT", buffer, strlen("PUIT")) == 0)
            {
                puit(atoi(choix), &ration, joueur, liste);
            }
            else if(strncmp("BANQUE", buffer, strlen("BANQUE")) == 0)
            {
                banque(atoi(choix), liste_banque, joueur);
            }
            else if(strncmp("PORTE", buffer, strlen("PORTE")) == 0)
            {
                action_carte(atoi(choix), joueur, carte);
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

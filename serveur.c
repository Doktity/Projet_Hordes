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

    while(joueur_liste_vide()){
        memset(buffer, 0, sizeof(buffer));
		lg = recv(client_socket, buffer, 512,0);

        if(strncmp("BONJOUR", buffer, 7) == 0){
			printf("[serveur] BONJOUR de %s\n", buffer+8);
            joueur = creer_joueur(buffer+8);
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
		
		if(strncmp("MSG", buffer, 3)==0){
			printf("[serveur] message reçu : '%s'\n",buffer+4);
			printf("[serveur] envoi de la réponse ");
            menu1 = buffer+4;
            if(strncmp(menu1, "maison", 6)==0){
                sprintf(buffer,"La maison de Mickey");
            }else if(strncmp(menu1, "puit", 4)==0){
                sprintf(buffer,"Attention au puit");
            }else if(strncmp(menu1, "banque", 6)==0){
                sprintf(buffer,"L'argent de la banque");
            }else if(strncmp(menu1, "citoyen", 7)==0){
                sprintf(buffer,"Les citoyens de la ville");
            }else if(strncmp(menu1, "chantier", 8)==0){
                sprintf(buffer,"Construction en cours");
            }else if(strncmp(menu1, "atelier", 7)==0){
                sprintf(buffer,"hop hop hop les matériaux");
            }else if(strncmp(menu1, "porte", 5)==0){
                sprintf(buffer,"La grande porte");
            }
			send(client_socket, buffer, 512, 0);
		} else if(strncmp("QUITTER", buffer, 7) == 0) {
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



#include "client.h"

void envoyer_message(int to_server_socket, char * buffer){
	char msg[200];
	sprintf(msg, "MSG %s", buffer);
	send(to_server_socket, msg, strlen(msg), 0); //on augmente la taille de 4 pour l'entête
	// lecture de la réponse
	memset(buffer, 0, sizeof(buffer));
	recv(to_server_socket,buffer,512,0);
	printf("[client] reponse du serveur : '%s'\n", buffer);
}

void quitter(int to_server_socket){
	printf("[client] envoi message QUITTER au serveur\n");
	send(to_server_socket,QUITTER,7,0);
}

int main (  int argc, char** argv )
{
    srand(time(NULL));

	struct sockaddr_in serveur_addr;
	struct hostent *serveur_info;
	long hostAddr;
	char buffer[512];
	int to_server_socket;

	bzero(&serveur_addr,sizeof(serveur_addr));
	hostAddr = inet_addr(SERVEURNAME);
	if ( (long)hostAddr != (long)-1 ){
		bcopy(&hostAddr,&serveur_addr.sin_addr,sizeof(hostAddr));
	} else {
		serveur_info = gethostbyname(SERVEURNAME);
	  	if (serveur_info == NULL) {
			printf("Impossible de récupérer les infos du serveur\n");
			exit(0);
	  	}
	  	bcopy(serveur_info->h_addr,&serveur_addr.sin_addr,serveur_info->h_length);
	}
	serveur_addr.sin_port = htons(30000);
	serveur_addr.sin_family = AF_INET;
	/* creation de la socket */
	if ( (to_server_socket = socket(AF_INET,SOCK_STREAM,0)) < 0) {
		printf("Impossible de créer la socket client\n");
	  	exit(0);
	}
	/* requete de connexion */
	if(connect( to_server_socket, (struct sockaddr *)&serveur_addr, sizeof(serveur_addr)) < 0 ) {
		printf("Impossible de se connecter au serveur\n");
	  	exit(0);
	}

    char nom[100];
    char bonjour[100];

    system("clear");

    printf("Nom : ");
    scanf("%s", nom);
    sprintf(bonjour, "BONJOUR %s", nom);

	/* envoie de données et reception */
	send(to_server_socket, bonjour, strlen(bonjour), 0);
	memset(buffer, 0, sizeof(buffer));
	recv(to_server_socket,buffer,512, 0);
	printf("[client] %s [du serveur]\n", buffer);

    /* Un menu pour faire differentes actions */
	int choix;
    do
    /* Affichage du menu et saisie du choix */
    {
		memset(buffer, 0, sizeof(buffer));

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
		{	case 1: sprintf(buffer, "maison");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 2: sprintf(buffer, "puit");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 3: sprintf(buffer, "banque");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 4: sprintf(buffer, "citoyen");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 5: sprintf(buffer, "chantier");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 6: sprintf(buffer, "atelier");
					envoyer_message(to_server_socket, buffer);
              		break;
      		case 7: sprintf(buffer, "porte");
					envoyer_message(to_server_socket, buffer);
              		break;
            case 8: send(to_server_socket, "QUITTER", 7, 0);
					break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 8\n");
		}
	}
	while(choix!=8);

	/* fermeture de la connexion */
	shutdown(to_server_socket,2);
	close(to_server_socket);
	return 0;
}



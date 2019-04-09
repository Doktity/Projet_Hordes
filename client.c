#include "client.h"

void envoyer_message(int to_server_socket, char * buffer){
	// Envoi du message
	char msg[200];
	sprintf(msg, "MSG %s", buffer);
	send(to_server_socket, msg, strlen(msg), 0);
	// lecture de la réponse
	memset(buffer, 0, sizeof(buffer));
	recv(to_server_socket,buffer,512,0);
	printf("[client] reponse du serveur : %s", buffer);
}


/**************************BATIMENTS**************************/

void menu_maison(int to_server_socket, char nom[MAX_TAILLE]){
	int choix;
	char * buffer = malloc(sizeof(buffer));
	system("clear");
	do
	/* Affichage du menu et saisie du choix */
	{
		printf("\nMaison\n------\nQue voulez-vous faire ?\n");
		printf(" 1 - Améliorer maison\n");
		printf(" 2 - Voir inventaire et coffre\n");
		printf(" 3 - Utiliser objet\n");
		printf(" 4 - Deposer objet\n");
		printf(" 5 - Prendre objet\n");
		printf(" 6 - Retour\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		if(choix > 0 && choix < 6)
		{
			sprintf(buffer, "MAISON %s %d", nom, choix);
			envoyer_message(to_server_socket, buffer);
		}
		else if(choix != 6)
		{
			printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	free(buffer);
}


void menu_puit (int to_server_socket, char nom[MAX_TAILLE]){
	int choix;
	char * buffer = malloc(sizeof(buffer));
	system("clear");
	do
	/* Affichage du menu et saisie du choix */
	{
		printf("\nPuit\n----\nQue voulez-vous faire ?\n");
		printf(" 1 - Prendre une ration d'eau\n");
		printf(" 2 - Rajouter de l'eau\n");
		printf(" 3 - Retour\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		if(choix > 0 && choix < 3)
		{
			sprintf(buffer, "PUIT %s %d", nom, choix);
			envoyer_message(to_server_socket, buffer);
		}
		else if(choix != 3)
		{
			printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=3);
	free(buffer);
}


void menu_banque(int to_server_socket, char nom[MAX_TAILLE]){
    int choix;
	char * buffer = malloc(sizeof(buffer));
	system("clear");
    do
	{
        printf("Bienvenue à la banque\n");
        printf("Que voulez-vous faire?\n");
        printf(" 1 - Afficher la liste des objets de la banque\n");
        printf(" 2 - Ajouter un objet dans la banque\n");
        printf(" 3 - Prendre un objet de la banque\n");
        printf(" 4 - Retour\n");
        printf("Votre choix:");
        scanf("%d",&choix);

        /* Traitement du choix de l'utilisateur */
		if(choix > 0 && choix < 4)
		{
			sprintf(buffer, "BANQUE %s %d", nom, choix);
			envoyer_message(to_server_socket, buffer);
		}
		else if(choix != 4)
		{
			printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
    }
	while(choix!=4);
	free(buffer);
}


void menu_porte(int to_server_socket, char nom[MAX_TAILLE]){
    int choix;
	char * buffer = malloc(sizeof(buffer));
  	system("clear");
    do
	{
		printf(" Quels actions voulez vous faire ?\n");
		printf(" 1 - vous déplacer à gauche\n");
		printf(" 2 - vous déplacer à droite\n");
		printf(" 3 - vous déplacer en haut\n");
		printf(" 4 - vous déplacer en bas\n");
		printf(" 5 - fouiller la zone\n");
		printf(" 6 - attaquer un zombie\n");
		printf(" 7 - ramasser objets\n");
		printf(" 8 - afficher la carte\n");
		printf(" 9 - sortir de la carte\n");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		if(choix > 0 && choix < 9)
		{
			sprintf(buffer, "PORTE %s %d", nom, choix);
			envoyer_message(to_server_socket, buffer);
		}
		else if(choix != 9)
		{
			printf("Erreur: votre choix doit etre compris entre 1 et 9\n");
		}
	}
	while (choix!=9);
	free(buffer);
}

/*************************************************************/


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

    char nom[MAX_TAILLE];

    system("clear");

    printf("Nom : ");
    scanf("%s", nom);
    sprintf(buffer, "BONJOUR %s", nom);
	send(to_server_socket, buffer, strlen(buffer), 0);
	memset(buffer, 0, sizeof(buffer));
	recv(to_server_socket,buffer,512,0);
	printf("[client] reponse du serveur : '%s'\n", buffer);

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
		{	case 1: menu_maison(to_server_socket, nom);
              		break;
			case 2: menu_puit(to_server_socket, nom);
              		break;
			case 3: menu_banque(to_server_socket, nom);
              		break;
			case 4: sprintf(buffer, "CITOYEN");
					send(to_server_socket, buffer, strlen(buffer), 0);
					memset(buffer, 0, sizeof(buffer));
					recv(to_server_socket,buffer,512,0);
					printf("[client] reponse du serveur : %s", buffer);
              		break;
			case 5: sprintf(buffer, "chantier");
					envoyer_message(to_server_socket, buffer);
              		break;
			case 6: sprintf(buffer, "atelier");
					envoyer_message(to_server_socket, buffer);
              		break;
      		case 7: menu_porte(to_server_socket, nom);
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



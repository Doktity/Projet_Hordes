#ifndef _SERVEUR_H_
#define _SERVEUR_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

//#define SERVEURNAME "192.168.1.106" // adresse IP de mon serveur
#define SERVEURNAME "127.0.0.1" // adresse IP de mon serveur

#define MAX_TAILLE 100

void envoyer_message(int to_server_socket, char * buffer);
void menu_maison(int to_server_socket, char nom[MAX_TAILLE]);
void menu_puit(int to_server_socket, char nom[MAX_TAILLE]);
void menu_banque(int to_server_socket, char nom[MAX_TAILLE]);
void menu_porte(int to_server_socket, char nom[MAX_TAILLE]);


#endif

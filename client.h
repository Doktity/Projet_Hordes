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

#define QUITTER "QUITTER"

void envoyer_message(int to_server_socket, char * buffer);
void quitter(int to_server_socket);



#endif
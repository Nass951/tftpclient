#include <sys/types.h>  
#include <sys/socket.h> 
#include <netdb.h>      
#include <arpa/inet.h>  
#include <unistd.h> 
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>  

#include "gettftp.h"



int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Récupération des informations
    char *server = argv[1];    // Adresse ou nom du serveur
    char *file = argv[2]; // Nom du fichier


    struct addrinfo hints,*res;
    memset(&hints,0,sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype=SOCK_DGRAM;
    int status = getaddrinfo(server, NULL, &hints, &res);
    
    
    if (res==NULL){
        printf("Res Null");
    }

    //affichage du res

    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
    struct addrinfo *p;
    for (p = res; p != NULL; p = p->ai_next) {

        status = getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof(host), serv, sizeof(serv), NI_NUMERICHOST | NI_NUMERICSERV);
        if (status != 0) {
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));
            continue;
        }
        printf("Adresse IPv4 : %s, Port : %s\n", host, serv);
        printf("ai_family : %d, ai_socktype : %d, ai_protocol : %d\n",p->ai_family, p->ai_socktype, p->ai_protocol);
    }



    if (status != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ipstr, sizeof(ipstr));//binaire en char


    

    int answer =gettftp(server,file,res);
    printf("Buffer non envoyée%d\n",answer);

    //affichage su serveur 
    printf("Serveur :%s \nFichier : %s\n",server,file);
    printf("Adresse IP : %s\n", ipstr);
    exit(EXIT_SUCCESS);
}   

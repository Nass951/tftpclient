#include <sys/types.h>  
#include <sys/socket.h> 
#include <netdb.h>      
#include <arpa/inet.h>  
#include <unistd.h> 
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>  
#include "gettftp.h"
#define RRQ_OPCODE 1  // Opcode pour une requête RRQ
#define MODE "octet"  // Mode de transfert TFTP (binaire)


int gettftp(char *server,char *filename,struct addrinfo *res){
    
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);//création du socket
    printf("Socket:%d\n",sock);

    // Requête RRQ
    char buffer[512];
    int offset = 0;
    buffer[offset++] = 0;          // Opcode haut
    buffer[offset++] = RRQ_OPCODE; // Opcode bas
    
    strcpy(&buffer[offset], filename);
    offset += strlen(filename) + 1; // +1 pour le caractère nul
    
    strcpy(&buffer[offset], MODE);  // Taille maximale d'un paquet TFTP
    offset += strlen(MODE) + 1;     // +1 pour le caractère nul

    printf("offset : %d \n", offset);
    // Envoi de la requête au serveur
    ssize_t sent_bytes = sendto(sock, buffer, offset, 0, res->ai_addr, res->ai_addrlen);
    
    
    if (sent_bytes == -1) {
        close(sock);
        return -1;  // Erreur d'envoi
    }
    return sock;
    

    printf("Requête RRQ envoyée avec succès : %zd octets\n", sent_bytes);
}
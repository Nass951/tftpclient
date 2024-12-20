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


int gettftp(char *server,char *filename,int sock){
    // Construction de la requête RRQ
    char buffer[512]; // Taille maximale d'un paquet TFTP
    int offset = 0;

    // Ajout de l'opcode (2 octets)
    buffer[offset++] = 0;            // Premier octet (opcode haut)
    buffer[offset++] = RRQ_OPCODE;   // Deuxième octet (opcode bas)

    // Ajout du nom du fichier
    strcpy(&buffer[offset], filename);
    offset += strlen(filename) + 1;  // +1 pour le caractère nul (\0)

    // Ajout du mode de transfert
    strcpy(&buffer[offset], MODE);
    offset += strlen(MODE) + 1;      // +1 pour le caractère nul (\0)

    // Envoi de la requête au serveur
    ssize_t sent_bytes = sendto(sock, buffer, offset, 0,res->ai_addr, sizeof(server_addr));
    if (sent_bytes == -1) {
        close(sock);
        return -1;  // Erreur d'envoi
    }
    return sock;
    

    printf("Requête RRQ envoyée avec succès : %zd octets\n", sent_bytes);
}
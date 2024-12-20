#include <sys/types.h>  
#include <sys/socket.h> 
#include <netdb.h>      
#include <arpa/inet.h>  
#include <unistd.h> 
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>  
#include "gettftp.h"
#define RRQ_OPCODE 1 
#define MODE "octet"  


int gettftp(char *server,char *filename,struct addrinfo *res){
    
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol); //To create the socket
    printf("Socket:%d\n",sock);

    // RRQ Request 
    char buffer[512];
    int offset = 0;
    buffer[offset++] = 0;          // High Opcode 
    buffer[offset++] = RRQ_OPCODE; // Low Opcode
    strcpy(&buffer[offset], filename);
    offset += strlen(filename) + 1; 
    strcpy(&buffer[offset], MODE);  
    offset += strlen(MODE) + 1;     
    printf("offset : %d \n", offset);//to see if the offset is right 
    


    // Send the request to the server
    ssize_t sent_bytes = sendto(sock, buffer, offset, 0, res->ai_addr, res->ai_addrlen);
    
    
    if (sent_bytes == -1) {
        close(sock);
        return -1;  // Error 
    }
    return sock;
    

    printf("Requête RRQ envoyée avec succès : %zd octets\n", sent_bytes);
}
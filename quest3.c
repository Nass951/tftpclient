int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];    // Server's name
    char *file = argv[2]; // File name 

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol); //To create the socket

    
    struct addrinfo hints,*res;
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype=SOCK_DGRAM;
    int status = getaddrinfo(server, "1069", &hints, &res);
    
    
    if (res==NULL){
        printf("Res Null");
    }

    /*Display of Res
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
    */
    
    printf("Serveur :%s \nFichier : %s\n",server,file);
    printf("Adresse IP : %s\n", ipstr);
    exit(EXIT_SUCCESS);
}
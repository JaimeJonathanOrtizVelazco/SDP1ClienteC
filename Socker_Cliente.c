//
// Created by thisisyj on 19/10/20.
//
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>

int Socket_Inet(
        char *Server,
        char *Service) {
    struct sockaddr_in Address;
    struct servent *Port;
    struct hostent *Host;
    int Descriptor;
    Port = getservbyname(Service, "tcp");
    if (Port == NULL)
        return -1;
    Host = gethostbyname(Server);
    if (Host == NULL)
        return -1;
    Address.sin_family = AF_INET;
    Address.sin_addr.s_addr = ((struct in_addr *) (Host->h_addr))->s_addr;
    Address.sin_port = Port->s_port;
    Descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (Descriptor == -1)
        return -1;
    if (connect(
            Descriptor,
            (struct sockaddr *) &Address,
            sizeof(Address)) == -1) {
        return -1;
    }
    return Descriptor;
}
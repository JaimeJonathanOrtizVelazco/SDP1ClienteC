//
// Created by thisisyj on 19/10/20.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "Socker_Cliente.h"
#include "Socket.h"

main() {
    int Server;
    int Size = 0;
    int Aux;
    char Sentence[7];
    Server = Socket_Inet("localhost", "cpp_java");
    if (Server == 1) {
        printf("No puedo establecer conexion con el servidor\n");
        exit(-1);
    }
    Socket_Reader(Server, (char *) &Aux, sizeof(int));
    Size = ntohl(Aux);
    printf("Recibido: %d\n", Size);
    Socket_Reader(Server, Sentence, Size);
    printf("Recibido: %s\n", Sentence);
    strcpy(Sentence, "Adios\0");
    Size = 6;
    Aux = htonl(Size);
    Socket_Writer(Server, (char *) &Aux, sizeof(Size));
    printf("Enviado: %d\n", Size);
    Socket_Writer(Server, Sentence, Size);
    printf("Enviado: %s\n", Sentence);
    close(Server);
}
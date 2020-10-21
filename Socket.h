//
// Created by thisisyj on 19/10/20.
//
#ifndef SDT1SERVIDOR_SOCKET_H
#define SDT1SERVIDOR_SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>

int Socket_Reader(int fd, char *Data, int Size);

int Socket_Writer(int fd, char *Data, int Size);

#endif
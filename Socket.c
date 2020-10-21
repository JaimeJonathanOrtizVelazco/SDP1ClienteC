//
// Created by thisisyj on 19/10/20.
//
#include <sys/un.h>
#include <unistd.h>
#include <errno.h>
#include "Socket.h"

int Socket_Reader(int fd, char *Data, int Size) {
    int isRead = 0;
    int Aux = 0;
    if ((fd == -1) || (Data == NULL) || (Size < 1))
        return -1;
    while (isRead < Size) {
        Aux = read(fd, Data + isRead, Size - isRead);
        if (Aux > 0) {
            isRead = isRead + Aux;
        } else {
            if (Aux == 0)
                return isRead;
            if (Aux == -1) {
                switch (errno) {
                    case EINTR:
                    case EAGAIN:
                        usleep(100);
                        break;
                    default:
                        return -1;
                }
            }
        }
    }
    return isRead;
}

int Socket_Writer(int fd, char *Data, int Size) {
    int isWrite = 0;
    int Aux = 0;
    if ((fd == -1) || (Data == NULL) || (Size < 1))
        return -1;
    while (isWrite < Size) {
        Aux = write(fd, Data + isWrite, Size - isWrite);
        if (Aux > 0) {
            isWrite = isWrite + Aux;
        } else {
            if (Aux == 0)
                return isWrite;
            else
                return -1;
        }
    }
    return isWrite;
}
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysockets.h"
//-----------------------------------------------------------------------------
int main(int argc,char * argv[]) {

    char Buffer[BUFFER_SIZE];
    int Socket;
    char *FGot;

    if ((Socket = CallSocket(argv[1],atoi(argv[2]))) == -1) {
        perror("CLIENT: Could not get socket");
        exit(EXIT_FAILURE);
    }

    printf("Enter a string to send: ");
    while ((FGot = fgets(Buffer,BUFFER_SIZE,stdin)) != NULL) {
        if (send(Socket,Buffer,strlen(Buffer),0) != strlen(Buffer)) {
            perror("CLIENT: Could not send string");
            exit(EXIT_FAILURE);
        }
        printf("Enter a string to send: ");
    }

    CloseSocket(Socket);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

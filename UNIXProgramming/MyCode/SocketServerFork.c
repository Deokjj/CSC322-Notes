//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mysockets.h"
//-----------------------------------------------------------------------------
//----Clean up any zombies
void ChildCatcher(int SignalNumber) {

    while (waitpid(-1, NULL, WNOHANG) > 0) {
    }
}
//-----------------------------------------------------------------------------
void DealWithConnection(int Socket) {

    char Buffer[BUFFER_SIZE + 1];
    int BytesRead;

    do {
        printf("SERVER: Waiting for data on socket\n");
        if ((BytesRead = recv(Socket,Buffer,BUFFER_SIZE,0)) > 0) {
            Buffer[BytesRead] = '\0';
            printf("%s",Buffer);
        }
    } while (BytesRead > 0);

    printf("SERVER: End of connection\n");
}
//-----------------------------------------------------------------------------
int main(int argc,char * argv[]) {

    int ListenSocket,ConnectionSocket;

    if (signal(SIGCHLD,ChildCatcher) == SIG_ERR) {
        perror("SERVER: Cannot catch SIGCHLD");
        exit(EXIT_FAILURE);
    }

    if ((ListenSocket = Establish(atoi(argv[1]))) < 0) {
        perror("SERVER: Error establishing listen socket");
        exit(EXIT_FAILURE);
    }

    while (1) {                         // loop for phone calls
        if ((ConnectionSocket = GetConnection(ListenSocket)) < 0) { 
            if (errno == EINTR) {       // EINTR might happen on accept(),
                continue;               // try again
            }
            perror("SERVER: Error on connection");
            exit(EXIT_FAILURE);
        }
        printf("SERVER: Received a connection\n");
        switch(fork()) {                  // try to handle connection
            case -1 :                     // bad news.  scream and die
                perror("SERVER: Error forking");
                CloseSocket(ListenSocket);
                CloseSocket(ConnectionSocket);
                exit(EXIT_FAILURE);
            case 0 :                          // we're the child, do something
                CloseSocket(ListenSocket);
                DealWithConnection(ConnectionSocket);
                CloseSocket(ConnectionSocket);
                exit(EXIT_SUCCESS);
            default :                         // we're the parent so look for
                CloseSocket(ConnectionSocket);     // another connection
                break;
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

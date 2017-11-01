//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "mysockets.h"
//-----------------------------------------------------------------------------
int CreateSocketAddress(char *Hostname,int PortNumber,
struct sockaddr_in *SocketAddress) {

    int Socket;
    struct hostent *HostEntry;

//----Get host entry and ensure it's an internet machine
    if ((HostEntry = gethostbyname(Hostname)) == NULL) {
        perror("Cannot get host entry");
        return(-1);
    }
    if (HostEntry->h_addrtype != AF_INET) {
        printf("ERROR: That's not an internet machine\n");
        return(-1);
    }

//----This is our host address and port number
    memset(SocketAddress,0,sizeof(struct sockaddr_in)); 
    SocketAddress->sin_family = AF_INET;
    SocketAddress->sin_port = htons(PortNumber);      
    memcpy(&SocketAddress->sin_addr,HostEntry->h_addr,HostEntry->h_length);
    
    if ((Socket = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("Cannot create socket");
        return(-1);
    }

    return(Socket);
}
//-----------------------------------------------------------------------------
int Establish(int PortNumber) { 

    char   MyName[MAX_HOST_NAME+1];
    struct sockaddr_in SocketAddress;
    int    Socket;

    gethostname(MyName,MAX_HOST_NAME);           
    if ((Socket = CreateSocketAddress(MyName,PortNumber,&SocketAddress)) 
== -1) {
        return(-1);
    }

    if (bind(Socket,(struct sockaddr*) &SocketAddress,sizeof(SocketAddress)) 
< 0) {
        perror("Cannot bind");
        CloseSocket(Socket);
        return(-1);
    }

    listen(Socket,MAX_SOCKET_QUEUE);

    return(Socket);
}
//-----------------------------------------------------------------------------
int CallSocket(char *Hostname,int PortNumber) {

    struct sockaddr_in SocketAddress;
    int Socket;

//----Create socket address
    if ((Socket = CreateSocketAddress(Hostname,PortNumber,&SocketAddress)) 
== -1) {
        return(-1);
    }

    if (connect(Socket,(struct sockaddr*) &SocketAddress,
sizeof(SocketAddress)) < 0) {
        perror("Cannot connect");
        CloseSocket(Socket);
        return(-1);
    }

    return(Socket);
}
//-----------------------------------------------------------------------------
//----Wait for a connection to occur on a socket
int GetConnection(int AcceptSocket) { 

    int ConnectionSocket;

    if ((ConnectionSocket = accept(AcceptSocket,NULL,NULL)) < 0) {
        return(-1);
    }

    return(ConnectionSocket);
}
//-----------------------------------------------------------------------------
void CloseSocket(int Socket) {

    close(Socket);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#ifndef MYSOCKETS_H
#define MYSOCKETS_H
//-----------------------------------------------------------------------------
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SOCKET_QUEUE 3
#define MAX_HOST_NAME 80
#define BUFFER_SIZE 256

int CreateSocketAddress(char *HostName,int PortNumber,
struct sockaddr_in *SocketAddress);
int Establish(int PortNumber);
int CallSocket(char *Hostname,int PortNumber);
int GetConnection(int AcceptSocket);
void CloseSocket(int Socket);
//-----------------------------------------------------------------------------
#endif

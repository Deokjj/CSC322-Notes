//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <netdb.h>

#define STRING_LENGTH 80
typedef char cstring[STRING_LENGTH];
//-----------------------------------------------------------------------------
int ctoi(int FromChar) {

    if (FromChar < 0) {
        return((FromChar & 0177) | 0200);
    } else {
        return(FromChar);
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    struct utsname UnameBuffer;
    cstring DomainName,HostName;
    struct hostent *HostEntry;
    char **Alias,**Address;

    uname(&UnameBuffer);
    printf("uname says ...\n");
    printf("Node name is    %s\n",UnameBuffer.nodename);
    printf("Machine is      %s\n",UnameBuffer.machine);
    printf("System name is  %s\n",UnameBuffer.sysname);
    printf("Version is      %s\n",UnameBuffer.version);
    printf("Release is      %s\n",UnameBuffer.release);
    printf("\n");

    printf("sysconf says ...\n");
    printf("Maximal processes per UID is %4ld\n",sysconf(_SC_CHILD_MAX));
    printf("Maximal files per process is %4ld\n",sysconf(_SC_OPEN_MAX));
    printf("\n");

    printf("getdtablesize says ...\n");
    printf("Maximal files per process is %4d\n",getdtablesize());
    printf("\n");

    printf("get*name says ...\n");
    gethostname(HostName,STRING_LENGTH);
    getdomainname(DomainName,STRING_LENGTH);
    printf("Host name is   %s\n",HostName);
    printf("Domain name is %s\n",DomainName);
    printf("\n");

    printf("gethostbyname says ...\n");
    HostEntry = gethostbyname(HostName);
    printf("Official host name is %s\n",HostEntry->h_name);
    Alias = HostEntry->h_aliases;
    while (*Alias != NULL) {
        printf("Alias for host is     %s\n",*Alias);
        Alias++;
    }
    Address = HostEntry->h_addr_list;
    while (*Address != NULL) {
        printf("Address for host is   %d.%d.%d.%d\n",ctoi((*Address)[0]),
ctoi((*Address)[1]),ctoi((*Address)[2]),ctoi((*Address)[3]));
        Address++;
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

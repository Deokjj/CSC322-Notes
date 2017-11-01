//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDOUT 1
//-----------------------------------------------------------------------------
int main(void) {

    int Descriptor;

    if ((Descriptor=dup(STDOUT)) == -1) {
        perror("duping STDOUT");
        exit(EXIT_FAILURE);
    }

    write(STDOUT,"output to stdout\n",17);
    write(Descriptor,"output to handle\n",17);

    close(Descriptor);
 
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

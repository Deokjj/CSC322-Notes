//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(int argc,char* argv[]) {

    if (link(argv[1],argv[2]) == -1) {
        perror(argv[1]);
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    if (unlink(argv[1]) == -1) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

//----Now-a-days there's a rename function available for this
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
//-----------------------------------------------------------------------------
int main(int argc,char* argv[]) {

    struct timeval TimeBuffer[2];

    TimeBuffer[0].tv_sec = 0;
    TimeBuffer[0].tv_usec = 0;
    TimeBuffer[1].tv_sec = 0;
    TimeBuffer[1].tv_usec = 0;
    
    if (utimes(argv[1],TimeBuffer) == -1) {
        perror(argv[1]);
        exit(errno);
    }

    if (chmod(argv[1],S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) == -1) {
        perror(argv[1]);
        exit(errno);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

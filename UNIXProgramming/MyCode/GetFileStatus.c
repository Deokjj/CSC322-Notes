//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
//-----------------------------------------------------------------------------
int main(int argc,char* argv[]) {

    struct stat StatusBuffer;

    if (stat(argv[1],&StatusBuffer) == -1) {
        perror(argv[1]);
        exit(errno);
    }

    printf("File name: %s\n",argv[1]);
    printf("Protection mode: %o\n",StatusBuffer.st_mode & 0777);
    printf("Number of links: %d\n",StatusBuffer.st_nlink);
    printf("Owner:           %s\n",getpwuid(StatusBuffer.st_uid)->pw_name);
    printf("Size:            %ld\n",StatusBuffer.st_size);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

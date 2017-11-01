//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define STRING_LENGTH 256
#define STDIN 0
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int FileDescriptor;
    char Buffer[STRING_LENGTH];

    if (argc == 2) {
        if ((FileDescriptor = open(argv[1],O_RDONLY)) < 0) {
            perror(argv[1]);
            exit(EXIT_FAILURE);
        }

        close(STDIN);
        if (dup2(FileDescriptor,STDIN) == -1) {
            perror("dup2 failed");
            exit(EXIT_FAILURE);
        }
        close(FileDescriptor);
    }

    while (fgets(Buffer,STRING_LENGTH,stdin) != NULL) {
        printf("=> %s",Buffer);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

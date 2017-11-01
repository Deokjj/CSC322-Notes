#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define COMMAND_LENGTH 128
//-----------------------------------------------------------------------------
int main(void) {

    char Command[COMMAND_LENGTH];
    int ChildPID;

    printf("?> ");
    fgets(Command,COMMAND_LENGTH,stdin);
    Command[strlen(Command)-1] = '\0';

    while (strcmp(Command,"exit") != 0) {
        if ((ChildPID = fork()) == -1) {
            perror("Could not fork");
            exit(EXIT_FAILURE);
        }

        if (ChildPID == 0) {
//----In the child
            execl(Command,Command,NULL);
//----Exit if the exec fails
            perror("Exec failed");
            exit(EXIT_FAILURE);
        } else {
//----Sleep to allow child to execute
            sleep(5);
            printf("?> ");
            fgets(Command,COMMAND_LENGTH,stdin);
            Command[strlen(Command)-1] = '\0';
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

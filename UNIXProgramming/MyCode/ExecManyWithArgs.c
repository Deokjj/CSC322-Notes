#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define COMMAND_LENGTH 128
//-----------------------------------------------------------------------------
void Undertaker(int TheSignal) {

    int DeadPID;
    int DeadStatus;

    DeadPID = wait(&DeadStatus);
    printf("Child %d completed with status %d\n",DeadPID,DeadStatus);

}
//-----------------------------------------------------------------------------
int main(void) {

    char Command[COMMAND_LENGTH];
    int ChildPID;
    int DeadPID;
    int DeadStatus;
    char *MyArgV[MAX_ARGS];
    int MyArgC;

//----Set up the undertaker
    if (signal(SIGCHLD,Undertaker) == SIG_ERR) {
        perror("Could not employ an undertaker");
        exit(EXIT_FAILURE);
    }

    printf("?> ");
    fgets(Command,COMMAND_LENGTH,stdin);
    Command[strlen(Command)-1] = '\0';

    while (strcmp(Command,"exit")) {
        if ((ChildPID = fork()) == -1) {
            perror("Could not fork");
            exit(EXIT_FAILURE);
        }
        if (ChildPID == 0) {
//----In the child
            MyArgC = 0;
            MyArgV[MyArgC] = strtok(Command," ");
            while (MyArgV[MyArgC++] != NULL) {
                MyArgV[MyArgC] = strtok(NULL," ");
            }
            execvp(MyArgV[0],MyArgV);
            fprintf(stderr,"Error in exec of %s\n",Command);
            fflush(stderr);
            exit(EXIT_FAILURE);
        } else {
            printf("?> ");
            fgets(Command,COMMAND_LENGTH,stdin);
            Command[strlen(Command)-1] = '\0';
        }
    }
//----I'll collect the remainder here
    if (signal(SIGCHLD,SIG_DFL) == SIG_ERR) {
        perror("Could not fire the undertaker");
        exit(EXIT_FAILURE);
    }
    printf("Parent will reap the remaining children\n");
    while ((DeadPID = wait(&DeadStatus)) != -1) {
        printf("Child %d completed with status %d\n",DeadPID,DeadStatus);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

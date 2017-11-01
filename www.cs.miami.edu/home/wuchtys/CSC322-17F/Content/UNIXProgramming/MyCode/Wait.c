#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COMMAND_LENGTH 128
#define MAX_ARGS 10
//-----------------------------------------------------------------------------
int main(void) {

    char Command[COMMAND_LENGTH];
    int ChildPID;
    char *MyArgV[MAX_ARGS];
    int MyArgC;
    int Status;

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
            perror("Error in exec");
            exit(EXIT_FAILURE);
        } else {
//----Wait to allow child to execute
            ChildPID = wait(&Status);
            printf("Child %d has exited\n",ChildPID);
            printf("?> ");
            fgets(Command,COMMAND_LENGTH,stdin);
            Command[strlen(Command)-1] = '\0';
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(void) {

    int ChildPID;

    printf("This is the parent process number %d\n",getpid());
    if ((ChildPID = fork()) == -1) {
        perror("Could not fork");
        exit(EXIT_FAILURE);
    }

    if (ChildPID == 0) {
//----In the child process
        printf("This is the child process, number %d parent number %d\n",
getpid(),getppid());
    } else {
//----Call sleep library function so that child can complete before parent
        sleep(2);
        printf("This is the parent process, with child number %d\n",ChildPID);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

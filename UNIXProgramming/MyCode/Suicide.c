#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(void) {

    int PID;

    if (kill(1,SIGKILL) == -1) {
        perror("Could not kill the OS");
    }

    if ((PID = getpid()) == -1) {
        perror("Could not get my PID");
    } else {
        printf("My PID is %d\n",PID);
        if (kill(PID,SIGKILL) == -1) {
            perror("Could not commit suicide");
        } else {
            printf("I'm dead, how can I print this?\n");
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
//-----------------------------------------------------------------------------
void Defence(int TheSignal) {

    printf("PARENT: Signaled\n");
    if (signal(SIGQUIT,SIG_DFL) == SIG_ERR) {
        perror("Could not reset signal handler");
    }
    printf("PARENT: Taken down the defence\n");
}
//-----------------------------------------------------------------------------
int main(void) {

    int PPID;
    int ChildPID;

    if ((ChildPID = fork()) == -1) {
        perror("Could not fork");
        exit(EXIT_FAILURE);
    }

    if (ChildPID == 0) {
//----In the child
        sleep(1);
        PPID = getppid();
        printf("CHILD: Parent is %d, kill!\n",PPID);
        if (kill(PPID,SIGQUIT) == -1) {
            perror("Could not send SIGQUIT to parent");
        }
        sleep(3);
        printf("CHILD: Parent is %d, kill again!\n",PPID);
        if (kill(PPID,SIGQUIT) == -1) {
            perror("Could not send SIGQUIT to parent");
        }
    } else {
        printf("PARENT: Putting up the defence\n");
        if (signal(SIGQUIT,Defence) == SIG_ERR) {
            perror("Could not install signal handler");
        }   
        printf("PARENT: I'm pausing\n\n");
        pause();
        printf("PARENT: I'm pausing again\n\n");
        pause();
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

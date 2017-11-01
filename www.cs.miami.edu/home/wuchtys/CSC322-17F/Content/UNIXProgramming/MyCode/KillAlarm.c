#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
void Defence(int TheSignal) {

    printf("PARENT: Signaled\n");
    if (signal(SIGQUIT,SIG_DFL) == SIG_ERR) {
        perror("Could not reset signal handler");
    }
    printf("PARENT: Taken down the defence\n");
    alarm(1);
}
//-----------------------------------------------------------------------------
void WakeUp(int TheSignal) {

    printf("PARENT: Putting up the defence again\n");
    if (signal(SIGQUIT,Defence) == SIG_ERR) {
        perror("Could not set SIGQUIT handler");
    }
}
//-----------------------------------------------------------------------------
void Fibonacci(int Index) {

    if (Index > 1) {
        Fibonacci(Index-1);
        Fibonacci(Index-2);
    }
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int PPID;
    int ChildPID;
    int Index = atoi(argv[1]);
    
    if ((ChildPID = fork()) == -1) {
        perror("Could not fork");
        exit(EXIT_FAILURE);
    }
    
    if (ChildPID == 0) {
        sleep(1);
        while ((PPID = getppid()) != 1) {
            printf("CHILD: Parent is %d, kill!\n",PPID);
            if (kill(PPID,SIGQUIT) == -1) {
                perror("Could not send SIGQUIT to parent");
            }
            printf("CHILD: Fibonacci %d\n",Index);
            Fibonacci(Index--);
        }
        printf("CHILD: I've been adopted\n");
    } else {
        printf("PARENT: Setting the alarm handler\n");
        if (signal(SIGALRM,WakeUp) == SIG_ERR) {
            perror("Could not set SIGALRM handler");
        }
        printf("PARENT: Putting up the defence\n");
        if (signal(SIGQUIT,Defence) == SIG_ERR) {
            perror("Could not set SIGQUIT handler");
        }
        while (1) {
            printf("PARENT: I'm pausing\n");
            pause();
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

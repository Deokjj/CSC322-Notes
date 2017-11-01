#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
 
#define TIME 3
#define MAX_TRYS 3
#define MAX_STRING 128

typedef char String[MAX_STRING];
//-----------------------------------------------------------------------------
void Timeout(int TheSignal) {

//----For old UNIX signal(SIGALRM,Timeout);
    printf("Come on ... ");
}
//-----------------------------------------------------------------------------
int main(void) {

    struct sigaction SignalHandling;
    int Trys;
    String Buffer;
    char * Result;

    SignalHandling.sa_handler = Timeout;
    SignalHandling.sa_flags = 0;
    if (sigaction(SIGALRM,&SignalHandling,NULL) == -1) {
        perror("Setting ALRM handler");
        exit(EXIT_FAILURE);
    }
%----Do not restart interrupted system calls
    if (siginterrupt(SIGALRM,1) == -1) {
        perror("Allowing interrupts");
        exit(EXIT_FAILURE);
    }

    Trys = 0;
    while (Trys < MAX_TRYS) {
        if (Trys == 0) {
            printf("Please enter a string within %d seconds\n",TIME);
        }
//----Set time out for TIME seconds, will signal SIGALRM
        alarm(TIME);
//----Attempt to read. 
        Result = fgets(Buffer,MAX_STRING,stdin);
//----Either read or signalled by here. Off alarm anyway
        alarm(0);
//----Determine what happened and deal with it
        if (Result == NULL) {
            printf("you're slow!\n");
            Trys++;
        } else {
//----Copy input to output
            printf("You entered ...\n    %s",Buffer);
            fflush(stdout);
            Trys = 0;
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

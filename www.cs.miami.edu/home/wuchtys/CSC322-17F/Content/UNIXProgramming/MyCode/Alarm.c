#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
void Timeout(int TheSignal) {

    printf("Wake up time\n");
}
//-----------------------------------------------------------------------------
int main(void) {

    if (signal(SIGALRM,Timeout) == SIG_ERR) {
        perror("Could not set SIGALRM handler");
        exit(EXIT_FAILURE);
    }
    printf("Alarm in 5 seconds\n");
    alarm(5);
    pause();
    printf("Woken up\n");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_TIME 20
//-----------------------------------------------------------------------------
void *IndependentLoop(void *Length) {

    extern int LastUser;
    int Delay;
    int TotalDelay;

    if ((Delay = atoi((char *)Length)) == 0) {
        fprintf(stderr,"ERROR: %s is not an integer\n",(char *)Length);
        return(NULL);
    }
    printf("Thread of %d starts\n",Delay);

    TotalDelay = 0;
    while (TotalDelay < TOTAL_TIME) {
        sleep(Delay);
        TotalDelay += Delay;
        printf("After thread of %d, thread of %d is up to %d\n",LastUser,
Delay,TotalDelay);
        LastUser = Delay;
    }

    printf("Thread of %d is completed\n",Delay);
    return(NULL);
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    extern int LastUser;
    int Index;
    pthread_t NewThread;

    LastUser = 0;
    for (Index = 1; Index < argc; Index++) {
        if (pthread_create(&NewThread,NULL,IndependentLoop,argv[Index]) != 0) {
           perror("Creating thread");
           exit(EXIT_FAILURE);
        }
        if (pthread_detach(NewThread) != 0) {
           perror("Detaching thread");
           exit(EXIT_FAILURE);
        }
    }

    printf("Exiting the main program, leaving the threads running\n");
    pthread_exit(NULL);

}
//-----------------------------------------------------------------------------
int LastUser;
//-----------------------------------------------------------------------------

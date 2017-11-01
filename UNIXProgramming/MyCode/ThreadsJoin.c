//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TOTAL_TIME 10
#define MAX_THREADS 10
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
    pthread_t NewThreads[MAX_THREADS];

    for (Index = 1; Index < argc; Index++) {
        if (pthread_create(&NewThreads[Index-1],NULL,IndependentLoop,
argv[Index]) != 0) {
           perror("Creating thread");
           exit(EXIT_FAILURE);
        }
    }

    for (Index = 0; Index < argc-1; Index++) {
        if (pthread_join(NewThreads[Index],NULL) != 0) {
            perror("Joining threads");
            exit(EXIT_FAILURE);
        }
        printf("Thread of %s terminated\n",argv[Index+1]);
    }

    return(0);
}
//-----------------------------------------------------------------------------
int LastUser;
//-----------------------------------------------------------------------------

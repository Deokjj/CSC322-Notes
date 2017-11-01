/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
/*---------------------------------------------------------------------------*/
void *Incrementer(void *Dummy) {

    extern int CommonInt;

    sleep(rand() % 4);
    if (CommonInt == 0) {
        sleep(rand() % 2);
        CommonInt += 1;
        printf("The common integer is now %d\n",CommonInt);
    }

    return(NULL);
}
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    extern int CommonInt;
    int Index;
    pthread_t NewThread;

    CommonInt = 0;
    srand(atoi(argv[2]));

    for (Index=0;Index<atoi(argv[1]);Index++) {
        if (pthread_create(&NewThread,NULL,Incrementer,NULL) != 0) {
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
/*---------------------------------------------------------------------------*/
int CommonInt;
/*---------------------------------------------------------------------------*/

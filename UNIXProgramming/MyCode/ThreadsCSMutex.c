/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
/*---------------------------------------------------------------------------*/
void *Incrementer(void *Dummy) {

    extern int CommonInt;
    extern pthread_mutex_t Mutex;

    sleep(rand() % 4);
    pthread_mutex_lock(&Mutex);
    if (CommonInt == 0) {
        sleep(rand() % 2);
        CommonInt += 1;
        printf("The common integer is now %d\n",CommonInt);
    }
    pthread_mutex_unlock(&Mutex);

    return(NULL);
}
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    extern int CommonInt;
    extern pthread_mutex_t Mutex;
    int Index;
    pthread_t NewThread;

    CommonInt = 0;
    srand(atoi(argv[2]));
    pthread_mutex_init(&Mutex,NULL);

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
pthread_mutex_t Mutex;
/*---------------------------------------------------------------------------*/

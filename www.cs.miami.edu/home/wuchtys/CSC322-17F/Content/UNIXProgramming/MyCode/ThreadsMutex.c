/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
/*---------------------------------------------------------------------------*/
void *Tackle(void *Dummy) {

    extern pthread_mutex_t Mutex;

    printf("Waiting for the snap\n");
    pthread_mutex_lock(&Mutex);
    pthread_mutex_unlock(&Mutex);
    printf("Tackle!!\n");

    return(NULL);
}
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    extern pthread_mutex_t Mutex;
    int Index;
    pthread_t NewThread;

    pthread_mutex_init(&Mutex,NULL);

    pthread_mutex_lock(&Mutex);
    for (Index=0;Index<atoi(argv[1]);Index++) {
        if (pthread_create(&NewThread,NULL,Tackle,NULL) != 0) {
           perror("Creating thread");
           exit(EXIT_FAILURE);
        }
        if (pthread_detach(NewThread) != 0) {
           perror("Detaching thread");
           exit(EXIT_FAILURE);
        }
    }

    fgetc(stdin);
    pthread_mutex_unlock(&Mutex);

    printf("Exiting the main program, leaving the threads running\n");
    pthread_exit(NULL);

}
/*---------------------------------------------------------------------------*/
pthread_mutex_t Mutex;
/*---------------------------------------------------------------------------*/

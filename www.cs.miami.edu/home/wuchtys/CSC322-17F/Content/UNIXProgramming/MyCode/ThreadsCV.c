/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
/*---------------------------------------------------------------------------*/
void *Tackle(void *Dummy) {

    extern pthread_cond_t Snap;
    extern pthread_mutex_t Mutex;

    pthread_mutex_lock(&Mutex);
    printf("Waiting for the snap\n");
    pthread_cond_wait(&Snap,&Mutex);
    pthread_mutex_unlock(&Mutex);
    printf("Tackle!!\n");

    return(NULL);
}
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    extern pthread_cond_t Snap;
    extern pthread_mutex_t Mutex;
    int Index;
    pthread_t NewThread;

    pthread_cond_init(&Snap,NULL);
    pthread_mutex_init(&Mutex,NULL);

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
    pthread_cond_broadcast(&Snap);

    printf("Exiting the main program, leaving the threads running\n");
    pthread_exit(NULL);

}
/*---------------------------------------------------------------------------*/
pthread_cond_t Snap;
pthread_mutex_t Mutex;
/*---------------------------------------------------------------------------*/

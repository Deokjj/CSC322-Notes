/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    pthread_mutex_t Mutex;
    pthread_cond_t Condition;
    int Value;
    } semaphore_type;
/*---------------------------------------------------------------------------*/
void Wait(semaphore_type *Semaphore) {

    pthread_mutex_lock(&(Semaphore->Mutex));
    Semaphore->Value--;
    if (Semaphore->Value < 0) {
        pthread_cond_wait(&(Semaphore->Condition),&(Semaphore->Mutex));
    }
    pthread_mutex_unlock(&(Semaphore->Mutex));
}
/*---------------------------------------------------------------------------*/
void Signal(semaphore_type *Semaphore) {

    pthread_mutex_lock(&(Semaphore->Mutex));
    Semaphore->Value++;
    if (Semaphore->Value <= 0) {
        pthread_cond_signal(&(Semaphore->Condition));
    }
    pthread_mutex_unlock(&(Semaphore->Mutex));
}
/*---------------------------------------------------------------------------*/
void *Incrementer(void *Dummy) {

    extern int CommonInt;
    extern semaphore_type MySemaphore;
    extern pthread_mutex_t IntMutex;

    sleep(rand() % 4);
    Wait(&MySemaphore);
    pthread_mutex_lock(&IntMutex);
    CommonInt--;
    printf("The common integer is now down to %d\n",CommonInt);
    pthread_mutex_unlock(&IntMutex);
    sleep(rand() % 2);
    pthread_mutex_lock(&IntMutex);
    CommonInt++;
    printf("The common integer is now up to   %d\n",CommonInt);
    pthread_mutex_unlock(&IntMutex);
    Signal(&MySemaphore);

    return(NULL);
}
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    extern int CommonInt;
    extern semaphore_type MySemaphore;
    extern pthread_mutex_t IntMutex;
    int Index;
    pthread_t NewThread;

    pthread_mutex_init(&MySemaphore.Mutex,NULL);
    pthread_cond_init(&MySemaphore.Condition,NULL);
    MySemaphore.Value = atoi(argv[2]);
    pthread_mutex_init(&IntMutex,NULL);

    CommonInt = atoi(argv[2]);
    srand(atoi(argv[3]));

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
semaphore_type MySemaphore;
pthread_mutex_t IntMutex;
/*---------------------------------------------------------------------------*/

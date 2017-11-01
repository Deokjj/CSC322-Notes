//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#define SLEEP_TARGET 30
#define MAX_THREADS 50
#define SHOOT_RATIO 4
//-----------------------------------------------------------------------------
void *IndependentLoop(void *Length) {

    int SleepLength,AccumulatedSleep,TargetIndex,BulletIndex,NumberOfBullets;
    int MyIndex;
    extern int NumberOfThreads;
    extern pthread_t ThreadVector[];
    extern int SleepLengths[];

//----Convert parameter to an integer
    if ((SleepLength = atoi((char *)Length)) == 0) {
        fprintf(stderr,"ERROR: %s is not an integer\n",(char *)Length);
        return(NULL);
    }
//----Find self in arrays
    MyIndex = 0;
    while (MyIndex < MAX_THREADS && !pthread_equal(ThreadVector[MyIndex],
pthread_self())) {
        MyIndex++;
    }
//----Sanity checks
    if (MyIndex == MAX_THREADS) {
        printf("ERROR: Thread not found in array\n");
        exit(EXIT_FAILURE);
    }
    if (SleepLength != SleepLengths[MyIndex]) {
        printf("ERROR: Thread parameter %s does not match external value %d\n",
(char *)Length,SleepLengths[MyIndex]);
        exit(EXIT_FAILURE);
    }

//----Initialize thread
    printf("Thread %2d (%2d) starts\n",MyIndex,SleepLength);
    srand(clock());

//----Thread must loop until is has accumulated enough sleep
    AccumulatedSleep = 0;
    while (AccumulatedSleep < SLEEP_TARGET) {
        printf("Thread %2d (%2d) goes to sleep\n",MyIndex,SleepLength);
        sleep(SleepLength);
        AccumulatedSleep += SleepLength;
        printf("Thread %2d (%2d) has accumulated %2d/%d\n",MyIndex,SleepLength,
AccumulatedSleep,SLEEP_TARGET);
//----Give thread bullets proportional to sleep length
        NumberOfBullets = SleepLength/SHOOT_RATIO;
        printf("Thread %2d (%2d) gets %2d bullets\n",MyIndex,SleepLength,
NumberOfBullets);
//----Fire at other threads
        for (BulletIndex = 0; BulletIndex < NumberOfBullets; BulletIndex++) {
            TargetIndex = rand() % NumberOfThreads;
            printf("Thread %2d (%2d) fires bullet %2d at thread %2d (%2d)",
MyIndex,SleepLength,BulletIndex+1,TargetIndex,SleepLengths[TargetIndex]);
//----Shoot at a thread known to be dead
            if (SleepLengths[TargetIndex] == 0) {
                printf(" and wastes a bullet\n");
//----Suicide is painless (according to MASH)
            } else if (pthread_equal(ThreadVector[TargetIndex],
pthread_self())) {
                SleepLengths[TargetIndex] = 0;
                printf(" and commits suicide!\n");
                pthread_exit(NULL);
            } else {
//----If the thread is alive, then the bullet is not wasted.
                SleepLengths[TargetIndex] = 0;
                printf(" and kills it!\n");
                if (pthread_cancel(ThreadVector[TargetIndex]) != 0) {
                    printf("ERROR: Could not cancel thread %2d (%2d) ",
TargetIndex,SleepLengths[TargetIndex]);
                    perror(":");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    printf("LIFE! Thread %2d (%2d) has completed\n",MyIndex,SleepLength);
    return(NULL);
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    extern int NumberOfThreads;
    extern pthread_t ThreadVector[];
    extern int SleepLengths[];
    int Index;

    for (Index = 0;Index < MAX_THREADS;Index++) {
        SleepLengths[Index] = 0;
    }
    srand(time(NULL));

    NumberOfThreads = 0;
    for (NumberOfThreads = 0; NumberOfThreads < argc-1; NumberOfThreads++) {
//----Store thread information
        SleepLengths[NumberOfThreads] = atoi(argv[NumberOfThreads+1]);
        if (pthread_create(&ThreadVector[NumberOfThreads],NULL,IndependentLoop,
argv[NumberOfThreads+1]) != 0) {
           perror("Creating thread");
           exit(EXIT_FAILURE);
        }
        printf("Started thread %2d (%2d)\n",NumberOfThreads,
SleepLengths[NumberOfThreads]);

//-----Detatch thread
        if (pthread_detach(ThreadVector[NumberOfThreads]) != 0) {
           perror("Detaching thread");
           exit(EXIT_FAILURE);
        }
    }

    printf("Exiting the main program, leaving the threads running\n");
    pthread_exit(NULL);

}
//-----------------------------------------------------------------------------
pthread_t ThreadVector[MAX_THREADS];
int SleepLengths[MAX_THREADS];
int NumberOfThreads;
//-----------------------------------------------------------------------------

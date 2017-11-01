//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define TOTAL_IO_TIME 10
#define STRING_LENGTH 80
typedef char cstring[STRING_LENGTH];
//-----------------------------------------------------------------------------
void CreateChild(int Pipe[2],int Delay) {

    cstring Message;
    int IOTime;

    if (pipe(Pipe) == -1) {
        perror("Creating pipe");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) {
        sprintf(Message,"Message from %d to %d, delay %d",Pipe[1],Pipe[0],
Delay);
        close(Pipe[0]);
        IOTime = 0;
//----Child send messages for a while, at delayed intervals
        while (IOTime < TOTAL_IO_TIME) {
            write(Pipe[1],Message,strlen(Message)+1);
            sleep(Delay);
            IOTime += Delay;
        }
        close(Pipe[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(Pipe[1]);
    }
}
//-----------------------------------------------------------------------------
void CheckDescriptor(int *Descriptor,fd_set *ReadSet,fd_set *OpenSet) {

    cstring Buffer;
    int NumberRead;

//----Check descriptor if a candidate
    if (FD_ISSET(*Descriptor,OpenSet) && FD_ISSET(*Descriptor,ReadSet)) {
        if ((NumberRead = read(*Descriptor,Buffer,STRING_LENGTH)) <= 0) {
            printf("==== EOF from %d\n",*Descriptor);
            FD_CLR(*Descriptor,OpenSet);
            close(*Descriptor);
        } else {
            printf("==== Data from %d: %s\n",*Descriptor,Buffer);
        }
    }
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int Pipe1[2],Pipe2[2];
    fd_set OpenSet,ReadSet;

    FD_ZERO(&OpenSet);
//----Create two child processes
    CreateChild(Pipe1,atoi(argv[1]));
    FD_SET(Pipe1[0],&OpenSet);
    CreateChild(Pipe2,atoi(argv[2]));
    FD_SET(Pipe2[0],&OpenSet);

//----Loop while either is being checked
    while (FD_ISSET(Pipe1[0],&OpenSet) || FD_ISSET(Pipe2[0],&OpenSet)) {
        ReadSet = OpenSet;
printf("-----------------------\n");
        if (select(FD_SETSIZE,&ReadSet,NULL,NULL,NULL) == -1) {
            perror("Selecting");
            exit(EXIT_FAILURE);
        }
        CheckDescriptor(&Pipe1[0],&ReadSet,&OpenSet);
        CheckDescriptor(&Pipe2[0],&ReadSet,&OpenSet);
    }

    return(EXIT_SUCCESS);

}
//-----------------------------------------------------------------------------

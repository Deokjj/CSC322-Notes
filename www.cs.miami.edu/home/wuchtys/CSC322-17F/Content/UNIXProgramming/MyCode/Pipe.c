//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MESSAGE_LENGTH 80
//-----------------------------------------------------------------------------
int main(void) {

    int FileDescriptors[2];
    int ChildPID;
    int NumberRead;
    char Message[MESSAGE_LENGTH];

//----Set up pipe to recieve data through
    if (pipe(FileDescriptors) == -1) {
        printf("ERROR: Could not create pipe\n");
        exit(EXIT_FAILURE);
    }

//----Fork to produce a producer
    if ((ChildPID = fork()) == -1) {
        perror("Could not fork");
        exit(EXIT_FAILURE);
    }

    if (ChildPID == 0) {
//----Child does not read from pipe
        close(FileDescriptors[0]);
//----Get strings from user and send to parent
        do {
            printf("CHILD: Enter a string:\n");
            fgets(Message,MESSAGE_LENGTH,stdin);
            if (strlen(Message) == 0) {
                close(FileDescriptors[1]);
                exit(EXIT_SUCCESS);
            }
            write(FileDescriptors[1],Message,strlen(Message));
        } while (1);

    } else {
//----Parent does not write to pipe
        close(FileDescriptors[1]);
//----Get strings from child
        do {
            NumberRead = read(FileDescriptors[0],Message,MESSAGE_LENGTH);
            if (NumberRead <= 0) {
                close(FileDescriptors[0]);
                exit(EXIT_SUCCESS);
            }
            Message[NumberRead] = '\0';
            printf("PARENT: Received %s\n",Message);
        } while (1);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

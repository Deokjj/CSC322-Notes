//-----------------------------------------------------------------------------
//----Program to  read a list of floats from a binary file. The first byte
//----of the file is an integer saying how many floats are in the file.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1000
//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {

    float BigBuffer[BUFFER_SIZE];
    int FileDescriptor;
    int BytesRead;
    int FileLength;
    int Index;

    if ((FileDescriptor = open(argv[1],O_RDONLY)) == -1) {
        perror("Opening datafile");
        exit(EXIT_FAILURE);
    }
    if ((BytesRead = read(FileDescriptor,&FileLength,sizeof(int))) != 
sizeof(int)) {
        perror("Reading datafile length");
        exit(EXIT_FAILURE);
    }
    if (FileLength > BUFFER_SIZE) {
        fprintf(stderr,"Too many floats, %d maximum\n",BUFFER_SIZE);
        exit(EXIT_FAILURE);
    }
    if ((BytesRead = read(FileDescriptor,BigBuffer,
FileLength*sizeof(float))) != FileLength*sizeof(float)) {
        perror("Reading datafile floats");
        exit(EXIT_FAILURE);
    }
    close(FileDescriptor);

    for (Index = 0; Index < FileLength; Index++) {
        printf("Float %d is %f\n",Index,BigBuffer[Index]);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

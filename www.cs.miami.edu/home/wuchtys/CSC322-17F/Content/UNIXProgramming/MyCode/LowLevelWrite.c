//-----------------------------------------------------------------------------
//----Program to write a bunch of floats to a binary file. The first byte
//----of the file is an integer saying how many floats are in the file.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {

    float BigBuffer[] = {2.3, -33.44, 99.99, 0.0, 1.11};
    int FileDescriptor;
    int BytesWritten;
    int ArraySize;

    ArraySize = sizeof(BigBuffer) / sizeof(float);

    if ((FileDescriptor = open(argv[1],O_CREAT|O_EXCL|O_WRONLY)) == -1) {
        perror("Opening datafile");
        exit(EXIT_FAILURE);
    }
    if ((BytesWritten = write(FileDescriptor,&ArraySize,sizeof(int))) != 
sizeof(int)) {
        perror("Writing datafile length");
        exit(EXIT_FAILURE);
    }
    if ((BytesWritten = write(FileDescriptor,BigBuffer,
ArraySize*sizeof(float))) != ArraySize*sizeof(float)) {
        perror("Writing datafile floats");
        exit(EXIT_FAILURE);
    }
    close(FileDescriptor);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

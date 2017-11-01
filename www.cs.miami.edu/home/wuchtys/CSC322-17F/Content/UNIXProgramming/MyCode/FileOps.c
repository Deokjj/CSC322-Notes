//-----------------------------------------------------------------------------
//----Simple program to make a private copy of the file in the first 
//----argument in the second argument. Will not overwrite an existing file
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BLOCK 32
#define STDOUT 1
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    char Buffer[BLOCK];
    int SourceDescriptor,DestinationDescriptor;
    int NumberRead,NumberWritten,TotalWritten;

    if ((SourceDescriptor = open(argv[1],O_RDONLY)) < 0) {
        perror(argv[1]);
        exit(-1);
    }

    if ((DestinationDescriptor = 
open(argv[2],O_WRONLY|O_CREAT|O_EXCL,S_IRWXU)) < 0) {
        perror(argv[2]);
        exit(-1);
    }

    while ((NumberRead = read(SourceDescriptor,Buffer,sizeof(Buffer))) > 0) {
        TotalWritten = 0;
        while (TotalWritten < NumberRead) {
            if ((NumberWritten = write(DestinationDescriptor,
Buffer+TotalWritten,NumberRead-TotalWritten)) == -1) {
                perror("Writing");
                exit(EXIT_FAILURE);
            }
            TotalWritten += NumberWritten;
        }
    }

//----Close destination now, because it's no longer needed and closing
//----flushes the directory entry to disk
    if (close(DestinationDescriptor) == -1) {
        perror("Closing destination");
    }
//----sync to get data out of buffers
    sync();

    if (lseek(SourceDescriptor,-BLOCK,2) == -1) {
        perror("lseek");
    } else {
        NumberRead = read(SourceDescriptor,Buffer,sizeof(Buffer));
        printf("Last %d bytes are:\n",NumberRead);
        write(STDOUT,Buffer,NumberRead);
    }

    if (close(SourceDescriptor) == -1) {
        perror("Closing source");
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILES 100
#define BUFFER_LENGTH 60
#define STDOUT 1
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int FileDescriptors[MAX_FILES];
    int NumberOfFiles,NumberOfOpenFiles;
    fd_set FilesToRead,OpenFiles;
    int Index;
    int NumberRead;
    char Buffer[BUFFER_LENGTH];

//----Open the files and record decriptors
    NumberOfFiles = 0;
    FD_ZERO(&OpenFiles);
    for (Index = 1;Index < argc;Index++) {
        if ((FileDescriptors[NumberOfFiles] = open(argv[Index],O_RDONLY,0)) 
== -1) {
            fprintf(stderr,"Error with %s ",argv[Index]);
            perror("Opening file - ignored");
        } else {
            FD_SET(FileDescriptors[NumberOfFiles],&OpenFiles);
            printf("File descriptor %2d is %s\n",FileDescriptors[NumberOfFiles],
argv[Index]);
            NumberOfFiles++;
        }
    }
    NumberOfOpenFiles = NumberOfFiles;

//----Loop while there are files to read
    while (NumberOfOpenFiles > 0) {
        FilesToRead = OpenFiles;

//----Who's got data for mama?
        if (select(FD_SETSIZE,&FilesToRead,NULL,NULL,NULL) == -1) {
            perror("Selecting");
            exit(-1);
        }
        for (Index= 0;Index < NumberOfFiles;Index++) {
            if (FD_ISSET(FileDescriptors[Index],&OpenFiles) &&
FD_ISSET(FileDescriptors[Index],&FilesToRead)) {
//----Read, leaving space for a \0 on the end 
                if ((NumberRead = read(FileDescriptors[Index],Buffer,
BUFFER_LENGTH-1)) <= 0) {
                    printf("==== EOF from %d\n",FileDescriptors[Index]);
                    FD_CLR(FileDescriptors[Index],&OpenFiles);
                    close(FileDescriptors[Index]);
                    NumberOfOpenFiles--;
                } else {
                    Buffer[NumberRead] = '\0';
                    printf("==== Data from FD %d\n",FileDescriptors[Index]);
                    printf("%s\n",Buffer);
                }
            }
        }
    }

    return(EXIT_SUCCESS);
                
}
//-----------------------------------------------------------------------------

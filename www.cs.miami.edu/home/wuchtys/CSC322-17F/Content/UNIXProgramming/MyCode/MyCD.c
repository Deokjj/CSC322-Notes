//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 128
//-----------------------------------------------------------------------------
int main(int argc,char *argv[])  { 

    char CWD[BUFFER_SIZE];

    printf("The process' directory is now %s\n",getcwd(CWD,BUFFER_SIZE));

    if (argc < 2) {  
        printf("Usage: %s <pathname>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    if (chdir(argv[1]) != 0) { 
        printf("Error in chdir\n");
        exit(EXIT_FAILURE);
    }

    printf("The process' directory is now %s\n",getcwd(CWD,BUFFER_SIZE));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

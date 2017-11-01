//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 80
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    FILE *FIFORead;
    char Buffer[STRING_LENGTH];

    if ((FIFORead = fopen(argv[1],"r")) == NULL) {
        perror("Opening FIFO to read");
        exit(EXIT_FAILURE);
    }

    while ((fgets(Buffer,STRING_LENGTH,FIFORead)) != NULL) {
        printf("Received from FIFO: %s",Buffer);
    }

    fclose(FIFORead);
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

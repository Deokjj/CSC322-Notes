//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int Index;
    
    printf("The run name is %s\n",argv[0]);

    for (Index = 1; Index < argc; Index++) {
        printf("Argument %d is %s, which is the integer %d\n",Index,
argv[Index],atoi(argv[Index]));
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

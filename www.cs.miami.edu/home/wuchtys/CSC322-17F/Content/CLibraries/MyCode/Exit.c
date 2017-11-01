//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
void ExitFunction(void) {

    printf("Goodbye\n");
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    atexit(ExitFunction);

    if (argc == 1) {
        printf("ERROR: Missing argument\n");
        exit(EXIT_FAILURE);
    }

    printf("Going to sleep for %d seconds ...\n",atoi(argv[1]));
    sleep(atoi(argv[1]));
    printf("That's all folks ... ");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

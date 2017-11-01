#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(void) {

    printf("About to sleep for 3 seconds\n");
    sleep(3);
    printf("Had a great sleep\n");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

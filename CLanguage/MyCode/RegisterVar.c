#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    register long RegisterVar = 0;

    while (1) {
        RegisterVar++;
        if (! (RegisterVar % 100000000)) {
            printf("%ld\n",RegisterVar);
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//-----------------------------------------------------------------------------
int main(void) {

    time_t ElapsedSinceEpoch;

    time(&ElapsedSinceEpoch);
    printf("%ld seconds\n",ElapsedSinceEpoch);
    printf("My time is %s\n",ctime(&ElapsedSinceEpoch));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

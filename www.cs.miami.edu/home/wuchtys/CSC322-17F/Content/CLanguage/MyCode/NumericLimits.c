#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <sys/limits.h>
//-----------------------------------------------------------------------------
int main(void) {

    printf("Short           %d - %d\n",SHRT_MIN,SHRT_MAX);
    printf("Unsigned Short  %d - %d\n",0,USHRT_MAX);
    printf("Int             %d - %d\n",INT_MIN,INT_MAX);
    printf("Unsigned Int    %d - %d\n",0,UINT_MAX);
    printf("Long            %ld - %ld\n",LONG_MIN,LONG_MAX);
    printf("Unsigned Long   %lu - %lu\n",0UL,ULONG_MAX);
    printf("Float           %e - %e\n",FLT_MIN,FLT_MAX);
    printf("Double          %e - %e\n",DBL_MIN,DBL_MAX);
    printf("Long Double     %Le - %Le\n",LDBL_MIN,LDBL_MAX);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

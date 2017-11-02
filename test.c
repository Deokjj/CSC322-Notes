//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt;

    int *PointAtInt;
    int *CopyPointer;

    AnInt = 27;
    PointAtInt = &AnInt;
    printf("AnInt = %d and %d\n",AnInt,*PointAtInt);

    *PointAtInt = 33;
    printf("AnInt = %d and %d\n",AnInt,*PointAtInt);

    CopyPointer = PointAtInt;
    *CopyPointer = 16;
    printf("AnInt = %d and %d\n",AnInt,*PointAtInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

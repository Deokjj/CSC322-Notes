//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt;
    int *PointAtAnInt;

    AnInt = 27;
    PointAtAnInt = &AnInt;
    printf("The pointer points to %d\n",*PointAtAnInt);

    PointAtAnInt = (int *)malloc(sizeof(int));
    *PointAtAnInt = 28;
    printf("The pointer points to %d\n",*PointAtAnInt);

    PointAtAnInt = &AnInt;
    printf("The pointer points to %d\n",*PointAtAnInt);

    free(PointAtAnInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

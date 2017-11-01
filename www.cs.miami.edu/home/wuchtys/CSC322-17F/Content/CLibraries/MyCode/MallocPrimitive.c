//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int *PointAtAnInt;

    // printf("The integer is %d\n",*PointAtAnInt);

    if ((PointAtAnInt = (int *)malloc(sizeof(int))) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    }

    printf("The integer is %d\n",*PointAtAnInt);
    *PointAtAnInt = 27;
    printf("The integer is %d\n",*PointAtAnInt);

    free(PointAtAnInt);

    // printf("The integer is %d\n",*PointAtAnInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

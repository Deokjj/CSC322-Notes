//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt;
    int *PointAtAnInt;
    int *PointNoWhere;
    int *NullPointer = NULL;

    AnInt = 16;
    PointAtAnInt = &AnInt;
    printf("The integer is %d\n",*PointAtAnInt);
    // printf("The null integer is %d\n",*NullPointer);

    printf("The non-existent integer is %d\n",*PointNoWhere);

    if (NullPointer != NULL) {
        printf("The non-null integer is %d\n",*NullPointer);
    } else {
        printf("That pointer is null\n");
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

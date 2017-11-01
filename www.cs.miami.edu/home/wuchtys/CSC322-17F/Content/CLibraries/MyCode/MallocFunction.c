//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
void * Malloc(size_t Size) {

    void * Memory;

    if ((Memory = malloc(Size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}
//-----------------------------------------------------------------------------
void Free(void ** Memory) {

    free(*Memory);
    *Memory = NULL;
}
//-----------------------------------------------------------------------------
int main(void) {

    int *PointAtAnInt;

    PointAtAnInt = (int *)Malloc(sizeof(int));

    printf("The integer is %d\n",*PointAtAnInt);
    *PointAtAnInt = 27;
    printf("The integer is %d\n",*PointAtAnInt);

    Free((void **)&PointAtAnInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

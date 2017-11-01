#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int OuterIndex;
    int Index;

    for (OuterIndex = 0; OuterIndex < 3; OuterIndex++) {
        int Index;
        printf("Outer index is %d\n",OuterIndex);
        for (Index = 0; Index < 3; Index++) {
            printf("Index is %d\n",Index);
        }
    }

    printf("\n");

    for (Index = 0; Index < 3; Index++) {
        int Index;
        for (Index = 0; Index < 3; Index++) {
            printf("Index is %d\n",Index);
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

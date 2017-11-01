//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4
//-----------------------------------------------------------------------------
int main(void) {

    int *TheData;
    int Size;
    int Index,LastIndex;
    int InputData;

    TheData = (int *)malloc(INITIAL_SIZE * sizeof(int));
    Size = INITIAL_SIZE;

    LastIndex = -1;
    printf("Enter data, 0 to exit : ");
    scanf("%d",&InputData);
    while (InputData != 0) {
        LastIndex++;
        if (LastIndex == Size) {
            Size *= 2;
            printf("Need more memory, increase to %d\n",Size);
            TheData = (int *)realloc(TheData,Size * sizeof(int));
        }
        TheData[LastIndex] = InputData;
        printf("Enter data, 0 to exit : ");
        scanf("%d",&InputData);
    }

    for (Index = 0; Index <= LastIndex; Index++) {
        printf("Item %d is %d\n",Index,TheData[Index]);
    }

    free(TheData);
    
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

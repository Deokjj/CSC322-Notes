#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
extern short TheData[];
void PrintBits(int HowMany);
//-----------------------------------------------------------------------------
int main(void) {

    extern int TheDataSize;
    int Index;

    for (Index = 0; Index < TheDataSize; Index++) {
        TheData[Index] = Index % 2;
    }
    PrintBits(TheDataSize / 2);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void PrintBits(int HowMany) {

    int Index;

    for (Index = 0; Index < HowMany; Index++) {
        printf("%d",TheData[Index]);
    }
    printf("\n");
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

typedef int DataArray[ARRAY_SIZE];
//-----------------------------------------------------------------------------
int main(void) {

    DataArray MyFibonaccis;
    int Index;
    int *ArrayBase;

    MyFibonaccis[0] = 0;
    MyFibonaccis[1] = 1;
    for (Index = 2; Index < ARRAY_SIZE; Index++) {
        MyFibonaccis[Index] = MyFibonaccis[Index-1] + MyFibonaccis[Index-2];
    }
    
    for (Index = 0; Index < ARRAY_SIZE; Index++) {
        printf("Direct Fibonacci number %d is %d\n",Index,MyFibonaccis[Index]);
    }

    ArrayBase = &MyFibonaccis[0];
    for (Index = 0; Index < ARRAY_SIZE; Index++) {
        printf("Offset pointer number %d is %d %d\n",Index,ArrayBase[Index],
*(ArrayBase+Index));
    }
    
    ArrayBase = &MyFibonaccis[2];
    for (Index = -2; Index < ARRAY_SIZE-2; Index++) {
        printf("Indexed pointer number %d is %d %d\n",Index,ArrayBase[Index],
*(ArrayBase+Index));
    }

    ArrayBase = &MyFibonaccis[ARRAY_SIZE-1];
    while (ArrayBase != MyFibonaccis) {
        printf("Directly pointed number is %d\n",*ArrayBase);
        ArrayBase--;
    }
    
    ArrayBase = &MyFibonaccis[3];
    printf("From %d to %d there are %d elements\n",*ArrayBase,
MyFibonaccis[ARRAY_SIZE-1],&MyFibonaccis[ARRAY_SIZE-1] - ArrayBase);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

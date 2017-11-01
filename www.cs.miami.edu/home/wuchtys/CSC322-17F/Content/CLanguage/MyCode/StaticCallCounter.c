#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
void CounterFunction(void);
//-----------------------------------------------------------------------------
int main(void) { 

    int Index;
 
    for (Index = 0; Index < 5; ++Index) {
        CounterFunction();
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void CounterFunction(void) {

    int AutomaticVariable = 0;
    static int StaticVariable = 0;
 
    printf("auto = %d, static = %d\n",AutomaticVariable,StaticVariable);
    ++AutomaticVariable;
    ++StaticVariable;
}
//-----------------------------------------------------------------------------

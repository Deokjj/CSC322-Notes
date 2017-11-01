#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
const static float PI = 3.14159265;
//-----------------------------------------------------------------------------
int main(void) {

    extern int Global;
    int UninitializedInt;
    int InitializedInt = 27;
    static int StaticInt;
    int Array[3] = {1,2,3};

    printf("PI is               %f\n",PI);
    printf("Global is           %d\n",Global);
    printf("UninitializedInt is %d\n",UninitializedInt);
    printf("InitializedInt is   %d\n",InitializedInt);
    printf("StaticInt is        %d\n",StaticInt);
    printf("Array[1] is         %d\n",Array[1]);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
int Global;
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
void Swap(int *This,int *WithThis) {

    int Temporary;

    Temporary = *This;
    *This = *WithThis;
    *WithThis = Temporary;
}
//-----------------------------------------------------------------------------
int main(void) {

    int I1,I2;

    I1 = 1;
    I2 = 2;
    printf("Before : %d %d\n",I1,I2);

    Swap(&I1,&I2);
    printf("After  : %d %d\n",I1,I2);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//----Do some powers
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX_AGE 110
//-----------------------------------------------------------------------------
int Power(int Base,int Exponent);
//-----------------------------------------------------------------------------
int main(void) {

    int BaseAndExponent;
    int Age;

    for (BaseAndExponent = 1; BaseAndExponent <= 4; BaseAndExponent++) {
        Age = Power(BaseAndExponent,BaseAndExponent);
        printf("When your age is %3d, you are %d^%d",
Age,BaseAndExponent,BaseAndExponent);
        if (Age >= MAX_AGE) {
            printf(", and you'll never get that old\n");
        } else {
            printf(", and you still plan to live for ever\n");
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
int Power(int Base,int Exponent) {

    int Result;

    for (Result=1;Exponent>0;--Exponent) {
        Result = Result*Base;
    }

    return(Result);
}
//-----------------------------------------------------------------------------

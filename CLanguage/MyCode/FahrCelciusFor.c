//----Print Fahrenheit-Celsius table for f = 0, 20, ...., 300.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int Fahrenheit;

    for (Fahrenheit = 0; Fahrenheit<300; Fahrenheit = Fahrenheit+20) {
        printf("%4d %6.1f\n",Fahrenheit,(5.0/9.0)*(Fahrenheit-32));
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//----Print Fahrenheit-Celsius table for f = 0, 20, ...., 300.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define LOWER 0     //----lower limit of table
#define UPPER 300   //----upper limit
#define STEP 20     //----step size
//-----------------------------------------------------------------------------
int main(void) {

    int Fahrenheit;

    for (Fahrenheit = LOWER; Fahrenheit <= UPPER; 
Fahrenheit = Fahrenheit+STEP) {
        printf("%4d %6.1f\n",Fahrenheit,(5.0/9.0)*(Fahrenheit-32));
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

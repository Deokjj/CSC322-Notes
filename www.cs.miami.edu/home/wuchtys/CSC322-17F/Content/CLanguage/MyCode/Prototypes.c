//----Fahrenheit-Celsius table
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define LOWER 0     //----lower limit of table
#define UPPER 300   //----upper limit        
#define STEP 20     //----step size         
//-----------------------------------------------------------------------------
void OutputTableRow(int,float);
float FahrenheitToCelsius(int);
//-----------------------------------------------------------------------------
int main(void) {

    int Fahrenheit;
    float Celcius;

    for (Fahrenheit = LOWER; Fahrenheit <= UPPER; 
Fahrenheit = Fahrenheit+STEP) {
        Celcius = FahrenheitToCelsius(Fahrenheit);
        OutputTableRow(Fahrenheit,Celcius);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void OutputTableRow(int Fahrenheit,float Celcius) {

    printf("%4d %6.1f\n",Fahrenheit,Celcius);
}
//-----------------------------------------------------------------------------
float FahrenheitToCelsius(int Fahrenheit) {

    float Result;

    Result = (5.0/9.0)*(Fahrenheit-32);
    return(Result);
}
//-----------------------------------------------------------------------------

/*---------------------------------------------------------------------------*/
/*----Modify the temperature conversion program to print a Celcius- */
/*----Fahrenheit conversion in reverse order, that is, from 148 to 17 */
/*----Celcius. */

#include <stdio.h>
/*---------------------------------------------------------------------------*/
int main(void) {

  int celcius;

  for (celcius=148;celcius>-17;celcius -=8)
    printf("%4d Celcius = %5.1f Fahrenheit\n",celcius,
	   (celcius * 9.0/5.0)+32);

  return(0);
}
/*---------------------------------------------------------------------------*/

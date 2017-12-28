//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define FEET_P_ATMOS 33			       	//define constant values
#define GROUPS_ARR "ABCDEFGHIJKLMLOPQRSTUVWXYZ"
//-----------------------------------------------------------------------------
float calcAmbientPressure(int depth);           //Declaration of functions
float calcO2Pressure(float ambientPressure,int o2);
char findGroup(float o2Pressure);
//-----------------------------------------------------------------------------
int main(void) {
	//variables declarations
	int depth, o2;
	float ambientPressure, o2Pressure;
	char groupToBelong;

	//keyboard input
	printf("\nEnter depth and percentage O2   : ");
	scanf("%d %d", &depth, &o2);

	//ask user again for input if invalid
	while(o2 <21 || o2 >40){
		printf("\nOxygen value must be 21 ~ 40 percent. Enter valid number");
		printf("\nEnter depth and percentage O2   : ");
 	        scanf("%d %d", &depth, &o2);
	}
	
	ambientPressure = calcAmbientPressure(depth);	
	o2Pressure = calcO2Pressure(ambientPressure,o2);	
	groupToBelong = findGroup(o2Pressure);

	//outputs
	printf("Ambient pressure                : %.1f\n", ambientPressure);
	printf("O2 pressure                     : %.2f\n", o2Pressure);	 
	printf("O2 group                        : %c\n", groupToBelong);
	printf("\n\n");
	printf("Exceeds maximal O2 pressure     : %s\n", o2Pressure > 1.4 ? "true" : "false");
	printf("Exceeds contingency O2 pressure : %s\n", o2Pressure > 1.6 ? "true" : "false");

	return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
float calcAmbientPressure(int depth) {
	return ((float)depth/33 + 1);
}
//-----------------------------------------------------------------------------
float calcO2Pressure(float ambientPressure,int o2) {
	return (float)o2/100*ambientPressure;
}
//-----------------------------------------------------------------------------
char findGroup(float o2Pressure) {
	//type conversion float to int automatically floors the float number.
	int index = (int) (o2Pressure*10);
	return GROUPS_ARR[index];
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

	float sideLand, roadLength;
	int numOfRoos;
	float roadWidth = 0.01;
	float probConst = 1.47;
	float expectedKills;	

	printf("Enter side of square in km  : ");
	scanf("%f", &sideLand);
	printf("Enter roads length in km    : ");
	scanf("%f", &roadLength);
	printf("Enter number of 'roos       : ");
	scanf("%d", &numOfRoos);

	//printf("%f - %f - %d",sideLand, roadLength, numOfRoos);
	//printf("\n");

	expectedKills = numOfRoos / (sideLand * sideLand ) * roadLength * roadWidth *probConst;
	printf("Expected number of kills is : %.1f \n", expectedKills);
	
	return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

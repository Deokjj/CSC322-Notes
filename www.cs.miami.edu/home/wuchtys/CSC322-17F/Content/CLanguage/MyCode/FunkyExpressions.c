#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_VALUES 4
//-----------------------------------------------------------------------------
int main(void) {

    float DataValues[MAX_DATA_VALUES];
    int NumberNegative,NumberOfDataValues,DataIndex;

    NumberOfDataValues = 0;
    do {
        printf("Enter data value %d (0 to exit) : ",NumberOfDataValues+1);
        scanf("%f",&DataValues[NumberOfDataValues++]);
    } while (DataValues[NumberOfDataValues-1] != 0 && 
NumberOfDataValues < MAX_DATA_VALUES);
    
    NumberNegative = 0;
    for (DataIndex = 0; DataIndex < NumberOfDataValues; DataIndex++) {
        NumberNegative += DataValues[DataIndex] < 0.0 ? 1 : 0;
    }
    printf("There %s %d negative value%s\n",NumberNegative == 1 ? "is" : "are",
NumberNegative,NumberNegative == 1 ? "" : "s");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

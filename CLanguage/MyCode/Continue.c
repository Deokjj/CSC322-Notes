#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_VALUES 10
//-----------------------------------------------------------------------------
int main(void) {

    int DataValues[MAX_DATA_VALUES];
    int NumberOfDataValues,DataIndex,SumOfPositive;

    NumberOfDataValues = 0;
    do {
        printf("Enter data value %d (0 to exit) : ",NumberOfDataValues+1);
        scanf("%d",&DataValues[NumberOfDataValues++]);
    } while (DataValues[NumberOfDataValues-1] != 0 && 
NumberOfDataValues < MAX_DATA_VALUES);
    
    SumOfPositive = 0;
    for (DataIndex = 0; DataIndex < NumberOfDataValues; DataIndex++) {
//----Disgusting way to do this - just for illustration
        if (DataValues[DataIndex] < 0.0) {
            continue;
        }
        SumOfPositive += DataValues[DataIndex];
    }
    printf("The sum of the positive values is %d\n",SumOfPositive);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

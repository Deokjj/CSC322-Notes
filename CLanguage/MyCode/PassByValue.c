//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void ReadIntByPointer(int *IntPointer);
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt;
    int *PointAtInt;

    AnInt = 27;
    printf("AnInt = %d\n\n",AnInt);

    PointAtInt = &AnInt;
    ReadIntByPointer(PointAtInt);
    printf("AnInt = %d\n\n",AnInt);

    ReadIntByPointer(&AnInt);
    printf("AnInt = %d\n\n",AnInt);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void ReadIntByPointer(int *IntPointer) {

    printf("Enter integer to assign by pointer   : ");
    scanf("%d",IntPointer);

}
//-----------------------------------------------------------------------------

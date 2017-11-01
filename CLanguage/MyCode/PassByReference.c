//-----------------------------------------------------------------------------
//----Contrived program to show ways of playing with pointers
#include <stdio.h>
#include <stdlib.h>

typedef int * IntPtr;
typedef IntPtr * IntPtrPtr;
//-----------------------------------------------------------------------------
void SwapPointers(IntPtrPtr IntPP1,IntPtrPtr IntPP2) {
//----or void SwapPointers(int **  IntPP1,int **  IntPP2)

    IntPtr Temporary;
//----or int * Temporary

    Temporary = *IntPP1;
    *IntPP1 = *IntPP2;
    *IntPP2 = Temporary;
}
//-----------------------------------------------------------------------------
void SwapInts(IntPtrPtr IntPP1,IntPtrPtr IntPP2) {
//---or void SwapInts(int ** IntPP1,int ** IntPP2)

    int Temporary;

    Temporary = **IntPP1;
    **IntPP1 = **IntPP2;
    **IntPP2 = Temporary;
}
//-----------------------------------------------------------------------------
int main(void) {

    int Data1,Data2;
    IntPtr DataPtr1,DataPtr2;
//----or int * DataPtr1,DataPtr2;

    Data1 = 27;
    Data2 = 16;
    DataPtr1 = &Data1;
    DataPtr2 = &Data2;
    printf("Data      : Data1     = %d, Data2     = %d\n",Data1,Data2);
    printf("DataPtr   : *DataPtr1 = %d, *DataPtr2 = %d\n",*DataPtr1,*DataPtr2);

    SwapPointers(&DataPtr1,&DataPtr2);
    printf("Data      : Data1     = %d, Data2     = %d\n",Data1,Data2);
    printf("DataPtr   : *DataPtr1 = %d, *DataPtr2 = %d\n",*DataPtr1,*DataPtr2);

    SwapInts(&DataPtr1,&DataPtr2);
    printf("Data      : Data1     = %d, Data2     = %d\n",Data1,Data2);
    printf("DataPtr   : *DataPtr1 = %d, *DataPtr2 = %d\n",*DataPtr1,*DataPtr2);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

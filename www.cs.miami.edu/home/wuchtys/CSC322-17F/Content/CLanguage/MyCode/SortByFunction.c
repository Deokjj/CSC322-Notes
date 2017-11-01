//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

//----Will sort 100 integers
#define NUMBERS 100
#define TRUE 1
#define FALSE 0

typedef int DataType[NUMBERS];
//-----------------------------------------------------------------------------
int CompareGreater(int This,int That) {

    return(This>That);
}
//-----------------------------------------------------------------------------
int CompareLess(int This,int That) {

    return(This<That);
}
//-----------------------------------------------------------------------------
void Swap(int *This,int *That) {

    int Temporary;

    Temporary = *This;
    *This = *That;
    *That = Temporary;
}
//-----------------------------------------------------------------------------
void Sort(DataType Data,int Size,int (*CompareFunction)(int,int)) {

    int Index,SwapOccured;

    SwapOccured = TRUE;
    while (SwapOccured) {
        SwapOccured=FALSE;
        for (Index=0; Index<Size-1; Index++)
            if ((*CompareFunction)(Data[Index],Data[Index+1])) {
                Swap(&Data[Index],&Data[Index+1]);
                SwapOccured = TRUE;
            }
    }
}
//-----------------------------------------------------------------------------
int GenerateData(DataType Data) {

    int HowMany,Index;

    printf("How many numbers (max %d) : ",NUMBERS);
    scanf("%d",&HowMany);
    for (Index=0; Index < HowMany; Index++) {
        Data[Index] = rand();
    }

    return(HowMany);
}
//-----------------------------------------------------------------------------
void OutputData(DataType Data,int HowMany) {

    int Index;

    printf("The numbers are\n");
    for (Index=0; Index < HowMany; Index++) {
        printf("%d ",Data[Index]);
    }
    printf("\n");

}
//-----------------------------------------------------------------------------
char InputDirection(void) {

    char Direction;

    printf("(A)scending or (D)ecending : ");
    scanf(" %c",&Direction);
    return(Direction);

}
//-----------------------------------------------------------------------------
int main(void) {

    DataType Data;
    int NumberOfNumbers;
    char Direction;

//----Input data and sort direction
    NumberOfNumbers=GenerateData(Data);
    OutputData(Data,NumberOfNumbers);
    Direction=InputDirection();
//----Call sort with correct comparison function
    if (Direction=='A' || Direction=='a') {
        Sort(Data,NumberOfNumbers,CompareGreater);
    } else {
        Sort(Data,NumberOfNumbers,CompareLess);
    }
//----Output sorted data
    OutputData(Data,NumberOfNumbers);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

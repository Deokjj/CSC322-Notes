//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
void PrintNames(char* Names[],int HowMany) {

    int Index;

    for (Index = 0; Index < HowMany; Index++) {
        printf("%s\n",Names[Index]);
    }
}
//-----------------------------------------------------------------------------
void SortNames(char* Names[],int HowMany) {

    int Swapped = 1;
    int Index;
    char* Temporary;

    while (Swapped) {
        Swapped = 0;
        for (Index = 0; Index < HowMany-1; Index++) {
            if (strcmp(Names[Index],Names[Index+1]) > 0) {
                Temporary = Names[Index];
                Names[Index] = Names[Index+1];
                Names[Index+1] = Temporary;
                Swapped = 1;
            }
        }
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    char* MonthNames[]= {
        "January",
        "Feburary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};

    PrintNames(MonthNames,12);
    SortNames(MonthNames,6);
    printf("\n");
    PrintNames(MonthNames,12);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

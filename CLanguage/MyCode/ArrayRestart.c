//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];
//-----------------------------------------------------------------------------
void PrintSubString(char * TheString,int Length) {

    int Index;

    for (Index = 0; Index < Length; Index++) {
        putchar(TheString[Index]);
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    String MyString = "Welcome to lovely Capetown";

    PrintSubString(MyString,2);
    PrintSubString(&MyString[10],5);
    PrintSubString(&MyString[17],2);
    printf("\n");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
//-----------------------------------------------------------------------------
int IntPrint(int NumberOfArguments,char Format,...) {

    int NumberPrinted,Value,ArgumentNumber;
    va_list Arguments;

    NumberPrinted = 0;
    va_start(Arguments,Format);
    for (ArgumentNumber = 1; ArgumentNumber <= NumberOfArguments;
ArgumentNumber++) {
        Value = va_arg(Arguments,int);
        switch (Format) {
            case 'd':
            case 'D':
                printf("%d\n",Value);
                break;
            case 'x':
            case 'X': 
                printf("%x\n",Value);
                break;
            case 'o':
            case 'O':
                printf("%o\n",Value); 
                break;
            default :
                printf("Error in format");
                return(-1);
                break;
        }
        NumberPrinted++;
    }
    va_end(Arguments);

    return(NumberPrinted);
}
//-----------------------------------------------------------------------------
int main(void) {

    int NumberPrinted;

    NumberPrinted = IntPrint(4,'x',123,456,789,-123);
    printf("\n%d items were printed\n",NumberPrinted);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

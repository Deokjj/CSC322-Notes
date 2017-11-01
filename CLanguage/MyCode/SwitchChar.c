#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    int C1,Index;
    int Whites,Others;
    int Digits[10];

    Whites = Others = 0;
    for (Index = 0; Index<10; ++Index) {
        Digits[Index] = 0;
    }

    while ((C1 = getchar()) != EOF) {
        switch(C1) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                Digits[C1-'0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                Whites++;
                break;
            default:
                Others++;
                break;
        }
    }

    printf("Digits =");
    for (Index = 0; Index<10; ++Index) {
        printf(" %d",Digits[Index]);
    }
    printf("\nWhite space = %d, Other = %d\n",Whites,Others);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

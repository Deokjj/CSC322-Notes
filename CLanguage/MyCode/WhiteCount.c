//----Counts digits, white space and others
//-----------------------------------------------------------------------------
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
        if (C1 >= '0' && C1 <= '9') {
            ++Digits[C1-'0'];
        } else {
            if (C1 == ' ' || C1 == '\n' || C1 == '\t') {
                ++Whites;
            } else {
                ++Others;
            }
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

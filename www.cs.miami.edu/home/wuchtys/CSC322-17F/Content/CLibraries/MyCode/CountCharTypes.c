//-----------------------------------------------------------------------------
//----Counts digits, control, punctuation, alpha, in the input
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//-----------------------------------------------------------------------------
int main(void) {

    int C1,Digits,Control,Punctuation,Alphabetic;

    Digits=Control=Punctuation=Alphabetic=0;

    while ((C1=getchar()) != EOF) {
        if (isalpha(C1)) {
            ++Alphabetic;
        } else if (iscntrl(C1)) {
            ++Control;
        } else if (isdigit(C1)) {
            ++Digits;
        } else if (ispunct(C1)) {
            ++Punctuation;
        }
    }

    printf("Digits = %d, Control = %d, Punctuation = %d, Alphabetic = %d\n",
Digits,Control,Punctuation,Alphabetic);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

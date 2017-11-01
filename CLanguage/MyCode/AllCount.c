//----Counts lines, words and chars in the input
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0
//-----------------------------------------------------------------------------
int main(void) {

    int Characters,Lines,Words;
    int InWord;
    int C1;

    InWord = NO;
    Lines = Words = Characters = 0;
    while ((C1 = getchar()) != EOF) {
        ++Characters;
        if (C1 == '\n') {
            ++Lines;
        }
        if (C1 == ' ' || C1 == '\n' || C1 == '\t') {
            InWord = NO;
        } else {
            if (!InWord) {
                InWord = YES;
                ++Words;
            }
        }
    }

    printf("\n%d %d %d\n",Characters,Words,Lines);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//----Count characters in input
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    long NumberOfCharacters;

    NumberOfCharacters = 0;
    while (getchar() != EOF) {
        ++NumberOfCharacters;
    }
    printf("\n%ld\n",NumberOfCharacters);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

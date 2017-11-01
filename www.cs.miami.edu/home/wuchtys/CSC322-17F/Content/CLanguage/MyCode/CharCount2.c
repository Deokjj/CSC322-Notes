//----Count characters in input, version 2
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    double NumberOfCharacters;

    for (NumberOfCharacters = 0; getchar() != EOF; ++NumberOfCharacters) {
    }
    printf("\n%.0f\n",NumberOfCharacters);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

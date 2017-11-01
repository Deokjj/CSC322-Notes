//----Copy input to output
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 80

typedef char String[STRING_LENGTH];
//-----------------------------------------------------------------------------
int main(void) {

    String S1;

    while (gets(S1) != NULL) {
        puts(S1);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

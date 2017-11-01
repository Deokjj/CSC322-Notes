//-----------------------------------------------------------------------------
//----This takes long lines and makes them into short lines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMAL_INPUT_LINE_LENGTH 10000
#define OUTPUT_LINE_LENGTH 70
//-----------------------------------------------------------------------------
int main(void) {

    char S1[MAXIMAL_INPUT_LINE_LENGTH];
    char *S1p;
    char Line[OUTPUT_LINE_LENGTH+1];

    while (fgets(S1,MAXIMAL_INPUT_LINE_LENGTH,stdin) != NULL) {
        S1p = S1;
        do {
            strncpy(Line,S1p,OUTPUT_LINE_LENGTH);
//----Ensure it's null terminated (strncpy does earlier nulls)
            Line[OUTPUT_LINE_LENGTH] = '\0';
            S1p += strlen(Line);
            puts(Line);
//----Keep going while there's anything left
        } while (strlen(S1p) > 0);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

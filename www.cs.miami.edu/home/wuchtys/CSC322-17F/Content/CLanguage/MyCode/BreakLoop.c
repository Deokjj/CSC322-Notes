#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
//-----------------------------------------------------------------------------
//----Remove trailing blanks and tabs
int main(void) {

    int Length;
    char Line[MAXLINE];

    fgets(Line,MAXLINE,stdin);
    Line[strlen(Line)-1] = '\0';
    while ((Length = strlen(Line)) > 0) {
        printf("Before cleaning \"%s\"\n",Line);
        while (--Length >= 0) {
            if (Line[Length] != ' ' && Line[Length] != '\t' &&
Line[Length] != '\n') {
                break;
            }
        }
        Line[Length+1]='\0';
        printf("After cleaning  \"%s\"\n",Line);

        fgets(Line,MAXLINE,stdin);
        Line[strlen(Line)-1] = '\0';
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

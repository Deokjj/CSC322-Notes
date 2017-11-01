//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    //----Maximum line input size
//-----------------------------------------------------------------------------
//----Get line into line and return length
int GetLine(void) {

    extern char Line[];
    int C1,Index;

    Index = 0;
    while (Index < MAXLINE-1 && (C1=getchar()) != EOF && C1!='\n') {
        Line[Index] = C1;
        Index++;
    }
    Line[Index] = '\0';

    return(Index);
}
//-----------------------------------------------------------------------------
//----Copies from to to
void Copy(void) {

    extern char Line[],Longest[];
    int Index;

    Index = 0;
    while ((Longest[Index] = Line[Index]) != '\0') {
        ++Index;
    }
}
//-----------------------------------------------------------------------------
//----Find longest line
int main(void) {

    extern char Longest[];
    int Length,            //----Current line length
        Maximum;           //----Maximum so far

    Maximum = 0;
//----Get lines and their lengths
    while ((Length = GetLine()) > 0) {
//----Test if longer, if so save line and length
        if (Length > Maximum) {
            Maximum = Length;
            Copy();
        }
    }

    if (Maximum > 0) {
        printf("\n%s\n",Longest);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
static char Line[MAXLINE],    //----Current input line
            Longest[MAXLINE];  //----Longest line so far
//-----------------------------------------------------------------------------

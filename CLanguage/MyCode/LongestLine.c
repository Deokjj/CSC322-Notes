//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000    //----Maximum line input size
//-----------------------------------------------------------------------------
//----Get line into line and return length
int GetLine(char Line[],int Limit) {

    int C1,Index;

    Index = 0;
    while (Index < Limit-1 && (C1=getchar()) != EOF && C1!='\n') {
        Line[Index] = C1;
        Index++;
    }
    Line[Index] = '\0';

    return(Index);
}
//-----------------------------------------------------------------------------
//----Copies from to to
void Copy(char From[],char To[]) {

    int Index;

    Index = 0;
    while ((To[Index] = From[Index]) != '\0') {
        ++Index;
    }
}
//-----------------------------------------------------------------------------
//----Find longest line
int main(void) {

    int Length,            //----Current line length
        Maximum;           //----Maximum so far
    char Line[MAXLINE],    //----Current input line
        Longest[MAXLINE];  //----Longest line so far

    Maximum = 0;
//----Get lines and their lengths
    while ((Length = GetLine(Line,MAXLINE)) > 0) {
//----Test if longer, if so save line and length
        if (Length > Maximum) {
            Maximum = Length;
            Copy(Line,Longest);
        }
    }

    if (Maximum > 0) {
        printf("\n%s\n",Longest);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

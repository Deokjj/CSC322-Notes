//-----------------------------------------------------------------------------
//----Checks that for every open bracket there's a corresponding closed one
//----This is not the same as balanced brackets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    char * OpenBrackets = "{[(<";
    char * CloseBrackets = "}])>";
    char * Open;
    char * Close;
    int Index;

    if (argc != 2) {
        printf("Usage: %s <string>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    Open = Close = argv[1];
//----Loop until no open bracket or error
    while (Open != NULL && Close != NULL) {
        printf("Now it's %s\n",Open);
//----See if there's another open bracket
        if ((Open = strpbrk(Open,OpenBrackets)) != NULL) {
            printf("Found open  %c\n",*Open);
//----Determine the corresponding close bracket
            Index = strchr(OpenBrackets,*Open) - OpenBrackets;
            printf("Look for %c\n",CloseBrackets[Index]);
//----Look for a corresponding close bracket
            if ((Close = strrchr(Open,CloseBrackets[Index])) != NULL) {
                printf("Found close %c\n",*Close);
//----If found, then reduce the string
                *Close = '\0';
                Open++;
            } else {
                Close = NULL;
            }
        }
    }

//----If exited because no open bracket, then OK
    if (Open == NULL) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }
                
    exit(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

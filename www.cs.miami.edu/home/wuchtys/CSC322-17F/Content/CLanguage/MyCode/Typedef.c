//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
#define STRING_LENGTH 1024

typedef int * IntPointer;
typedef char String[STRING_LENGTH];
//-----------------------------------------------------------------------------
void SplitAtColon(String WholeString,String Prefix,IntPointer PrefixLength) {

    String WholeCopy;
    char * Colon;

    strcpy(WholeCopy,WholeString);
    if ((Colon = strchr(WholeCopy,':')) != NULL) {
        *Colon = '\0';
        strcpy(Prefix,WholeCopy);
    } else {
        strcpy(Prefix,WholeCopy);
    }
    *PrefixLength = strlen(Prefix);
}
//-----------------------------------------------------------------------------
int main(void) {

    String UserString;
    String Prefix;
    int PrefixLength;

    printf("Please enter your string : ");
    scanf("%s",UserString);

    SplitAtColon(UserString,Prefix,&PrefixLength);

    printf("Prefix (%2d) : %s\n",PrefixLength,Prefix);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

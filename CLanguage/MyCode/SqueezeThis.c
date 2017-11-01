//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 128

typedef char String[MAX_STRING_LENGTH];
//-----------------------------------------------------------------------------
//----Deletes all DeleteThis from FromThis
void Squeeze(char DeleteThis,char FromThis[]) { 

    int TakeFromIndex,PutAtIndex;

    for (TakeFromIndex = PutAtIndex = 0; FromThis[TakeFromIndex] != '\0';
TakeFromIndex++) {
        if (FromThis[TakeFromIndex] != DeleteThis) {
            FromThis[PutAtIndex++] = FromThis[TakeFromIndex];
        }
    }
    FromThis[PutAtIndex]='\0';
}
//-----------------------------------------------------------------------------
int main(void) {

    String UserString;
    int C1;

    printf("Enter your string    : ");
    fgets(UserString,MAX_STRING_LENGTH,stdin);
    UserString[strlen(UserString)-1] = '\0';
    printf("Enter char to delete : ");
    C1 = getchar();

    printf("The original string is \"%s\"\n",UserString);
    Squeeze(C1,UserString);
    printf("After deleting '%c' the string is \"%s\"\n",C1,UserString);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

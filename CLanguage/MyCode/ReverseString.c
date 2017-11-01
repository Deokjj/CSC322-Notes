//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 128

typedef char String[MAX_STRING_LENGTH];
//-----------------------------------------------------------------------------
void Reverse(String ToReverse) {

    int C1,ForwardsIndex,ReverseIndex;

    for (ForwardsIndex=0,ReverseIndex = strlen(ToReverse)-1;
ForwardsIndex < ReverseIndex; ForwardsIndex++,ReverseIndex--) {
        C1 = ToReverse[ForwardsIndex];
        ToReverse[ForwardsIndex] = ToReverse[ReverseIndex];
        ToReverse[ReverseIndex] = C1;
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    String UserString;

    printf("Enter your string : ");
    fgets(UserString,MAX_STRING_LENGTH,stdin);
    UserString[strlen(UserString)-1] = '\0';

    printf("The original string is \"%s\"\n",UserString);
    Reverse(UserString);
    printf("The reversed string is \"%s\"\n",UserString);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

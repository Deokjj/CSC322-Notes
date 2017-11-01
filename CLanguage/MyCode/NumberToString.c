#include <stdio.h>
#include <stdlib.h>

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
//----Converts number to string form
void itoa(int Number,String StringForm) {

    int StringIndex,Sign;

//----Record sign
    if ((Sign = Number) < 0) {
        Number = -Number;
    }

//----Generate in reverse order
    StringIndex = 0;
    do {
        StringForm[StringIndex++]=Number % 10 + '0';
//---Until 0
    } while ((Number /= 10) > 0);

    if (Sign < 0) {
        StringForm[StringIndex++]='-';
    }
    StringForm[StringIndex]='\0';
    Reverse(StringForm);
}
//-----------------------------------------------------------------------------
int main(void) {

    int UserNumber;
    String AsAString;

    printf("Enter your Integer : ");
    scanf("%d",&UserNumber);

    itoa(UserNumber,AsAString);

    printf("The number is %d, and as a string it's %s\n",UserNumber,AsAString);
    
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

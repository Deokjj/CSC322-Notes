//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
//----Date to year day
int main(void) {

    int DayTable[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int Year,Month,Day;
    int Index,Leap;

    printf("What year month day? : ");
    scanf("%d %d %d",&Year,&Month,&Day);

    Leap = Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0);
    for (Index = 1; Index < Month; Index++) {
         Day += DayTable[Leap][Index];
    }

    printf("That's day number %d\n",Day);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int DayInYear(int LocalTable[][13],int Year,int Month,int Day) {

    int Index,Leap;

    Leap = Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0);
    for (Index = 1; Index < Month; Index++) {
         Day += LocalTable[Leap][Index];
    }

    return(Day);
}
//-----------------------------------------------------------------------------
//----Date to year day
int main(void) {

    int DayTable[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int Year,Month,Day;

    printf("What year month day? : ");
    scanf("%d %d %d",&Year,&Month,&Day);
    printf("That's day number %d\n",DayInYear(DayTable,Year,Month,Day));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

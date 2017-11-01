//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
typedef struct {
    char *Name;
    int Score;
} ScoredNamesType;
//-----------------------------------------------------------------------------
void PrintScoredNames(ScoredNamesType Names[],int HowMany) {

    int Index;

    for (Index = 0; Index < HowMany; Index++) {
        printf("%2d %s\n",Names[Index].Score,Names[Index].Name);
    }
}
//-----------------------------------------------------------------------------
void ScoreNames(ScoredNamesType Names[],int HowMany) {

    int Index;

    for (Index = 0; Index < HowMany; Index++) {
        Names[Index].Score = strlen(Names[Index].Name);
    }
}
//-----------------------------------------------------------------------------
int CompareLengths(void const *A, void  const *B) {

    return (((ScoredNamesType *)A)->Score - ((ScoredNamesType *)B)->Score);
}
//-----------------------------------------------------------------------------
int main(void) {

    ScoredNamesType MonthNames[] = {
        {"January",0},
        {"Feburary",0},
        {"March",0},
        {"April",0},
        {"May",0},
        {"June",0},
        {"July",0},
        {"August",0},
        {"September",0},
        {"October",0},
        {"November",0},
        {"December",0}
    };

    PrintScoredNames(MonthNames,12);
    ScoreNames(MonthNames,12);
    printf("\n");
    PrintScoredNames(MonthNames,12);
    qsort(MonthNames,6,sizeof(ScoredNamesType),CompareLengths);
    printf("\n");
    PrintScoredNames(MonthNames,12);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128

typedef char String[MAX_STRING];

typedef struct {
    String Site;
    int Depth;
    int Time;
    char PressureGroup;
} DiveRecordType;
//-----------------------------------------------------------------------------
void PrintDive(DiveRecordType Dive) {

    printf("Site           %-10s\n",Dive.Site);
    printf("Depth          %3d\n",Dive.Depth);
    printf("Time           %3d\n",Dive.Time);
    printf("Pressure group %3c\n",Dive.PressureGroup);
}
//-----------------------------------------------------------------------------
int main(void) {

    DiveRecordType LastDive;

    strcpy(LastDive.Site,"Jupiter");
    LastDive.Depth = 81;
    LastDive.Time = 40;
    LastDive.PressureGroup = 'P';

    PrintDive(LastDive);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

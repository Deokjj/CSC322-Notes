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
DiveRecordType InputDive(void) {

    DiveRecordType Dive;

    printf("What was the dive site      : ");
    scanf("%s",Dive.Site);
    printf("What was the dive depth     : ");
    scanf("%d",&Dive.Depth);
    printf("What was the dive time      : ");
    scanf("%d",&Dive.Time);
    printf("What was the pressure group : ");
//----Note leading space to eat white space
    scanf(" %c",&Dive.PressureGroup);

    return(Dive);
}
//-----------------------------------------------------------------------------
void InitializeDive(DiveRecordType *Dive) {

    strcpy(Dive->Site,"Bayahibe Beach, Dominican Republic");
    Dive->Depth = 555;
    Dive->Time = 8;
    Dive->PressureGroup = 'D';
}
//-----------------------------------------------------------------------------
int main(void) {

    DiveRecordType LastDive;

    InitializeDive(&LastDive);
    PrintDive(LastDive);

    LastDive = InputDive();
    PrintDive(LastDive);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

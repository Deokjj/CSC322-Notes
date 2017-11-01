//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128
#define MAX_DIVES 1000

typedef char String[MAX_STRING];

typedef struct {
    String Site;
    int Depth;
    int Time;
    char PressureGroup;
} DiveRecordType;

typedef DiveRecordType DiveBookType[MAX_DIVES];
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

    strcpy(Dive->Site,"");
    Dive->Depth = 0;
    Dive->Time = 0;
    Dive->PressureGroup = ' ';
}
//-----------------------------------------------------------------------------
void InitializeLogbook(DiveBookType Book) {

    int Index;

    for (Index = 0; Index < MAX_DIVES; Index++) {
        InitializeDive(&Book[Index]);
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    DiveBookType Logbook;
    int DiveNumber;

    InitializeLogbook(Logbook);

    printf("Which dive number to enter : ");
    scanf("%d",&DiveNumber);
    Logbook[DiveNumber] = InputDive();
    PrintDive(Logbook[DiveNumber]);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

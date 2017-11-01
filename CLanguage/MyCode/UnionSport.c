//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128

typedef char String[MAX_STRING];

typedef enum {
    SCUBA,
    basejumping,
    motoX,
    error
} SportType;
    
typedef struct {
    int Depth;
    int Time;
    char PressureGroup;
} DiveRecordType;

typedef struct {
    float Height;
} JumpRecordType;

typedef struct {
    int EngineCapacity;
    char TrickLevel;
} MotoXRecordType;

typedef union {
    DiveRecordType DiveRecord;
    JumpRecordType JumpRecord;
    MotoXRecordType MotoXRecord;
} SportUnionType;

typedef struct {
    SportType Sport;
    String Site;
    SportUnionType Record;
} SportRecordType;
//-----------------------------------------------------------------------------
SportType InputSportType(void) {

    String Sport;

    scanf("%s",Sport);
    if (!strcmp(Sport,"SCUBA")) {
        return(SCUBA);
    }
    if (!strcmp(Sport,"basejumping")) {
        return(basejumping);
    }
    if (!strcmp(Sport,"motoX")) {
        return(motoX);
    }
    return(error);
}
//-----------------------------------------------------------------------------
char* StringSportType(SportType Sport) {

    switch (Sport) {
        case SCUBA:
            return("SCUBA");
            break;
        case basejumping:
            return("basejumping");
            break;
        case motoX:
            return("motoX");
            break;
        default:
            return("error");
            break;
    }
}
//-----------------------------------------------------------------------------
void PrintDive(DiveRecordType Dive) {

    printf("Depth          %3d\n",Dive.Depth);
    printf("Time           %3d\n",Dive.Time);
    printf("Pressure group %3c\n",Dive.PressureGroup);
}
//-----------------------------------------------------------------------------
DiveRecordType InputDive(void) {

    DiveRecordType Dive;

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
void PrintJump(JumpRecordType Jump) {

    printf("Height         %6.2f\n",Jump.Height);
}
//-----------------------------------------------------------------------------
JumpRecordType InputJump(void) {

    JumpRecordType Jump;

    printf("What was the jump height    : ");
    scanf("%f",&Jump.Height);

    return(Jump);
}
//-----------------------------------------------------------------------------
void PrintMotoX(MotoXRecordType MotoX) {

    printf("Engine capacity %3d\n",MotoX.EngineCapacity);
    printf("Trick level     %3c\n",MotoX.TrickLevel);
}
//-----------------------------------------------------------------------------
MotoXRecordType InputMotoX(void) {

    MotoXRecordType MotoX;

    printf("What was the engine capacity: ");
    scanf("%d",&MotoX.EngineCapacity);
    printf("What was the trick level    : ");
//----Note leading space to eat white space
    scanf(" %c",&MotoX.TrickLevel);

    return(MotoX);
}
//-----------------------------------------------------------------------------
void PrintSportRecord(SportRecordType SportRecord) {

    printf("Sport was       %s\n",StringSportType(SportRecord.Sport));
    printf("Event site      %-10s\n",SportRecord.Site);
    switch (SportRecord.Sport) {
        case SCUBA:
            PrintDive(SportRecord.Record.DiveRecord);
            break;
        case basejumping:
            PrintJump(SportRecord.Record.JumpRecord);
            break;
        case motoX:
            PrintMotoX(SportRecord.Record.MotoXRecord);
            break;
        default:
            printf("error");
            break;
    }
}
//-----------------------------------------------------------------------------
SportRecordType InputSportRecord(void) {

    SportRecordType InputData;

    printf("What was the sport          : ");
    InputData.Sport = InputSportType();
    printf("What was the site           : ");
    scanf("%s",InputData.Site);
    switch (InputData.Sport) {
        case SCUBA:
            InputData.Record.DiveRecord = InputDive();
            break;
        case basejumping:
            InputData.Record.JumpRecord = InputJump();
            break;
        case motoX:
            InputData.Record.MotoXRecord = InputMotoX();
            break;
        default:
            printf("error");
            break;
    }

    return(InputData);
}
//-----------------------------------------------------------------------------
int main(void) {

    SportRecordType LastActivity;

    LastActivity = InputSportRecord();
    PrintSportRecord(LastActivity);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

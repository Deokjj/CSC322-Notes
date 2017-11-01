//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSTRING 128

typedef char CString[MAX_CSTRING];

typedef struct {
    CString FamilyName;
    CString GivenName;
} PersonType;

#define PRETTY_PRINT(This) printf("\n----------------\n%s\n----------------\n",(This))

//-----------------------------------------------------------------------------
void SetNames(CString NewFamilyName,CString NewGivenName,PersonType *APerson) {

    strcpy(APerson->FamilyName,NewFamilyName);
    strcpy(APerson->GivenName,NewGivenName);
}
//-----------------------------------------------------------------------------
void GetFullName(PersonType APerson,CString FullName) {

    strcpy(FullName,APerson.GivenName);
    strcat(FullName," ");
    strcat(FullName,APerson.FamilyName);
}
//-----------------------------------------------------------------------------
int main(void) {

    PersonType MyPerson;
    CString InputFamilyName;
    CString InputGivenName;
    CString FullName;
    CString OutputLine;

    printf("Please enter the given name and family name : ");
    scanf(" %s %s",InputGivenName,InputFamilyName);
    SetNames(InputFamilyName,InputGivenName,&MyPerson);
    GetFullName(MyPerson,FullName);

    sprintf(OutputLine,"The full name is %s",FullName);
    PRETTY_PRINT(OutputLine);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

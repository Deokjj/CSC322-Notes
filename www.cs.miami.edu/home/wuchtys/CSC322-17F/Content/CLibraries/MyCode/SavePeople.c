//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRING_LENGTH 80

typedef char String[STRING_LENGTH];

typedef struct {
    String Name;
    int Age;
    float Income;
} PersonType;
//-----------------------------------------------------------------------------
int ReadPerson(PersonType *InputPerson) {

    printf("Enter name, age, and income  : ");
    return(scanf(" %s %d %f",InputPerson->Name,&InputPerson->Age,
&InputPerson->Income) != EOF);
    }
//-----------------------------------------------------------------------------
void EchoPerson(PersonType InputPerson) {

    printf("%-20s, %3d years, $%.2f per year\n",InputPerson.Name,
InputPerson.Age,InputPerson.Income);
}
//-----------------------------------------------------------------------------
void MakeFileName(String PeopleType,String SaveFileName) {

    int Index;

    strcpy(SaveFileName,PeopleType);
    for (Index = 0; Index<strlen(SaveFileName); Index++) {
        if (!isalnum(SaveFileName[Index])) {
            SaveFileName[Index] = '_';
        }
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    String PeopleType;
    String SaveFileName;
    PersonType InputPerson;
    FILE *PeopleFile;

    printf("What type of people are these : ");
    fgets(PeopleType,STRING_LENGTH,stdin);
    PeopleType[strlen(PeopleType)-1] = '\0';
    MakeFileName(PeopleType,SaveFileName);

//----Open a file to save the people in
    if ((PeopleFile = fopen(SaveFileName,"w")) == NULL) {
        perror("Opening people file");
        exit(EXIT_FAILURE);
    }

//----Save the people type
    strcat(PeopleType,"\n");
    if (fputs(PeopleType,PeopleFile) == EOF) {
        perror("Writing people type to file");
        exit(EXIT_FAILURE);
    }

//----Read, echo, and save
    while (ReadPerson(&InputPerson)) {
        EchoPerson(InputPerson);
        if (fwrite(&InputPerson,sizeof(PersonType),1,PeopleFile) != 1) {
            perror("Writing PersonType to file");
            exit(EXIT_FAILURE);
        }
    }

    fclose(PeopleFile);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

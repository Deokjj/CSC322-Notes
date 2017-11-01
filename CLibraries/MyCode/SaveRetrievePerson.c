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

//----Copy across people type
    strcpy(SaveFileName,PeopleType);
//----Replace non-alphanumeric with _
    for (Index = 0; Index < strlen(SaveFileName); Index++) {
        if (!isalnum(SaveFileName[Index])) {
            SaveFileName[Index] = '_';
        }
    }
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    String PeopleType;
    String SaveFileName;
    PersonType InputPerson;
    FILE *PeopleFile;

//----If one command line argument, then retrieve from that file
    if (argc >= 3) {
//----Open file to read people from
        if ((PeopleFile = fopen(argv[1],"r")) == NULL) {
            perror("Opening people file");
            exit(EXIT_FAILURE);
        }

//----Read the people type
        if (fgets(PeopleType,STRING_LENGTH,PeopleFile) == NULL) {
            perror("Reading people type from file");
            exit(EXIT_FAILURE);
        }

//----Seek to the required PersonType
        if (fseek(PeopleFile,(atoi(argv[2])-1)*sizeof(PersonType),SEEK_CUR) != 
0) {
            perror("Seeking PersonType");
            exit(EXIT_FAILURE);
        }
        if (fread(&InputPerson,sizeof(PersonType),1,PeopleFile) != 1) {
            perror("Reading PersonType");
            exit(EXIT_FAILURE);
        }
        fclose(PeopleFile);

        EchoPerson(InputPerson);

//----Else save people
    } else {
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
                perror("Writing person to file");
                exit(EXIT_FAILURE);
            }
        }

        fclose(PeopleFile);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

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
int main(void) {

    String PeopleType;
    PersonType InputPerson;

    printf("What type of people are these : ");
    fgets(PeopleType,STRING_LENGTH,stdin);

    while (ReadPerson(&InputPerson)) {
        EchoPerson(InputPerson);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

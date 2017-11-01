/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 80
/*---------------------------------------------------------------------------*/
int main(void) {

    char Name[STRING_LENGTH];
    int Age;
    float Income;

    printf("Enter name, age, and income  : ");
    scanf("%s %d %f",Name,&Age,&Income);
    printf("%-20s, %3d years, $%.2f per year\n",Name,Age,Income);

    return(EXIT_SUCCESS);
}
/*---------------------------------------------------------------------------*/


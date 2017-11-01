//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];

typedef char* CharPointer;
//-----------------------------------------------------------------------------
int main(void) {

    String AWord = "recieve";
    CharPointer ArrayOfPointers[strlen(AWord)];
    int Index;

    printf("The original word is  %s\n",AWord);

    printf("The iterative word is ");
    for (Index = 0; Index < strlen(AWord); Index++) {
        printf("%c",AWord[Index]);
        ArrayOfPointers[Index] = &AWord[Index];
    }
    printf("\n");

    printf("The pointed word is   ");
    for (Index = 0; Index < strlen(AWord); Index++) {
        printf("%c",*(ArrayOfPointers[Index]));
    }
    printf("\n");


    ArrayOfPointers[3] = &AWord[4];
    ArrayOfPointers[4] = &AWord[3];
    printf("The fixed word is     ");
    for (Index=0;Index < strlen(AWord);Index++) {
        printf("%c",*(ArrayOfPointers[Index]));
    }
    printf("\n");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

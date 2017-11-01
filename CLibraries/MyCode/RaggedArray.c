//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
#define MAX_STRING_LENGTH 1024

typedef char String[MAX_STRING_LENGTH];
//-----------------------------------------------------------------------------
void * Malloc(size_t Size) {

    void * Memory;

    if ((Memory = malloc(Size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}
//-----------------------------------------------------------------------------
void Free(void ** Memory) {

    free(*Memory);
    *Memory = NULL;
}
//-----------------------------------------------------------------------------
int main(void) {

    char ** UserSayings;
    int Index;
    String UserInput;
    int NumberOfSayings;

    printf("How many sayings do you have: ");
    scanf("%d",&NumberOfSayings);
//----Eat the newline
    fgets(UserInput,MAX_STRING_LENGTH,stdin);
//----Alocate the first dimension
    UserSayings = Malloc(NumberOfSayings * sizeof(char *));

    for (Index=0; Index < NumberOfSayings; Index++) {
        printf("Please enter your saying: ");
        fgets(UserInput,MAX_STRING_LENGTH,stdin);
//----Chomp the newline
        UserInput[strlen(UserInput)-1] = '\0';
//----Store the saying
        UserSayings[Index] = Malloc((strlen(UserInput)+1) * sizeof(char));
        strcpy(UserSayings[Index],UserInput);
    }
    
    printf("\nYou said ...\n");
    for (Index=0;Index < NumberOfSayings;Index++) {
        printf("   %s\n",UserSayings[Index]);
        Free((void**)&(UserSayings[Index]));
    }
    Free((void **)&UserSayings);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(int argc, char *argv[], char *envv[]) {

    int Index;
    extern char ** environ;
//----For some reason char *environ[] doesn't work

    for (Index = 0; Index < argc; Index++) {
        printf("The %dth argument is %s\n",Index,argv[Index]);
    }
    printf("\n");

    for (Index = 0; envv[Index] != NULL; Index++) {
        printf("The %dth argument environment string is %s\n",Index,
envv[Index]);
    }
    printf("\n");

    for (Index = 0; environ[Index] != NULL; Index++) {
        printf("The %dth external environment string is %s\n",Index,
environ[Index]);
    }
    printf("\n");

    printf("The PATH environment string is %s\n",getenv("PATH"));
    if (setenv("SOUP","mulligatawny",1) == -1) {
        perror("Setting SOUP value");
        return(EXIT_FAILURE);
    } 
    printf("The SOUP environment string is %s\n",getenv("SOUP"));
    unsetenv("SOUP");
    if (getenv("SOUP") == NULL) {
        printf("No soup for you!\n");
    } 

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

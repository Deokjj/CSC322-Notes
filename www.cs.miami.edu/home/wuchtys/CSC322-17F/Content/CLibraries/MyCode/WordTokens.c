//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 80
#define SEPARATORS " .,?\"\n\t"
//-----------------------------------------------------------------------------
int main(void) {

    char Line[LINE_LENGTH];
    char *Word;

    printf("Enter line, up to %d characters.\n",LINE_LENGTH);
    while (fgets(Line,LINE_LENGTH,stdin) != NULL) {
        printf("The words in that line are:\n");
//----Find the first word
        Word = strtok(Line,SEPARATORS);
        while (Word != NULL) {
            printf("%s\n",Word);
            Word = strtok(NULL,SEPARATORS);
        }
        printf("Enter line, up to %d characters.\n",LINE_LENGTH);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

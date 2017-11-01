//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128

typedef char String[MAX_STRING];
//-----------------------------------------------------------------------------
int main(void) {

    String Sentence = "The evil matrix will sink in the swamp of reason";
    String UserInput;

    printf("%s\n",Sentence);
    printf("What's your word? : ");
    scanf("%s",UserInput);
    if (strstr(Sentence,UserInput) != NULL) {
        printf("That's in the sentence\n");
    } else {
        printf("That's not in the sentence\n");
    }

    strcpy(Sentence,"");
    printf("Enter a word for your sentence : ");
    scanf("%s",UserInput);
    while (strcmp(UserInput,".")) {
        strcat(Sentence,UserInput);
        strcat(Sentence," ");
        printf("Enter a word for your sentence, '.' to end : ");
        scanf("%s",UserInput);
    }
    Sentence[strlen(Sentence)-1]  = '.';
    printf("%s\n",Sentence);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

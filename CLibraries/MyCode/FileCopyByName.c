//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
//----Copy a file
int main(int argc, char* argv[]) {

    FILE *InputFile;
    FILE *OutputFile;
    int C1;

    if (argc != 3) {
        printf("ERROR: File names not given\n");
        return(EXIT_FAILURE);
    }

    if ((InputFile = fopen(argv[1],"r")) != NULL &&
(OutputFile = fopen(argv[2],"w")) != NULL) {
        while ((C1 = fgetc(InputFile)) != EOF) {
            if (fputc(C1,OutputFile) == EOF) {
                printf("Error writing file\n");
                exit(EXIT_FAILURE);
//----exit will close the file
            }
        }
        if (fclose(InputFile) == EOF || fclose(OutputFile) == EOF) {
            printf("Error closing files\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

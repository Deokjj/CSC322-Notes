#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMAL_GROWING_STRING_LENGTH 1024
#define MAXIMAL_INPUT_LINE_LENGTH 100
#define IAM "I am "
#define PERIOD "."
#define COMMA_SPACE ", "
#define FILE_NAME "MyQualities.txt"

void fileAppend(FILE * f, char * s){
 f = fopen(FILE_NAME, "a");
 fprintf(f,"%s\n",s);
 fclose(f);
}

void openFile(FILE * f){
  int c;
  printf("Confirming the saved qualities ...\n");
  f = fopen(FILE_NAME,"r");
  while ((c = getc(f)) != EOF)
    putchar(c);
  fclose(f);
}

int main(void) {
  char allQualities[MAXIMAL_GROWING_STRING_LENGTH] = "";
  char input[MAXIMAL_INPUT_LINE_LENGTH];
  char *qualityS;

  // open file for writes - need not exist, will create
  FILE *f = fopen(FILE_NAME, "w");
  if (f == NULL){	
    printf("Error opening file!\n");
    exit(1);
  }
  else fclose(f);

  printf("Please enter sentences, . to end.\n");
  while (fgets(input,MAXIMAL_INPUT_LINE_LENGTH,stdin) != NULL) {
    //break if "." entered. strtok removes trailing new line
    if(strlen(input) >1 && strcmp(strtok(input, "\n"),PERIOD) == 0) break;

    //see if starts with "I am"
    qualityS = strstr(input,IAM);
    if(qualityS != NULL ){
      //pointer to the qualiity part only
      qualityS = (qualityS+5);
      if(strlen(qualityS) >1){
        //if allQualities string is empty, comma is not added
        if(allQualities[0] != '\0') strcat(allQualities, COMMA_SPACE);
        strncat(allQualities, qualityS, strlen(qualityS));
	
        fileAppend(f, qualityS);
      }
    }  
  }

  printf("The qualities are : %s.\n\n",allQualities);

  openFile(f);
  //removes file.
  remove(FILE_NAME);  
		
  return (EXIT_SUCCESS);
}

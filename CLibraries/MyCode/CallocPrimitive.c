//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------
int main(void) {

    char *Message = "Hello crool world";
    char *PointAtString;

    printf("Uninitialized PointAtString is %s\n",PointAtString);
    PointAtString = Message;
    printf("Initialized PointAtString is %s\n",PointAtString);
    PointAtString = (char *)calloc(strlen(Message)+1,sizeof(char));
    printf("Malloced PointAtString is %s\n",PointAtString);
    strcpy(PointAtString,Message);
    printf("Copied PointAtString is %s\n",PointAtString);

    free(PointAtString);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

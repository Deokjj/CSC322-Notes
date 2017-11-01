//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];
//-----------------------------------------------------------------------------
int main(void) {

    String MyArray;
    char MyMessage[] = "hello world";
    char *OSMessage = "don't touch me";
    char *NoMemory;

    printf("MyArray = %s\n",MyArray);
    strcpy(MyArray,MyMessage);
    printf("MyArray = %s\n",MyArray);
    strcpy(MyArray,OSMessage);
    printf("MyArray = %s\n",MyArray);

    printf("Now let's live dangerously\n");
    printf("MyMessage = %s\n",MyMessage);
    strcpy(MyMessage,"shorty lives");
    printf("MyMessage = %s\n",MyMessage);
    strcpy(MyMessage,"a long life is great");
    printf("MyMessage = %s\n",MyMessage);

    printf("OSMessage = %s\n",OSMessage);
    strcpy(OSMessage,"attack the OS");
    printf("OSMessage = %s\n",OSMessage);

    printf("NoMemory = %s\n",NoMemory);
    strcpy(NoMemory,OSMessage);
    printf("NoMemory = %s\n",NoMemory);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

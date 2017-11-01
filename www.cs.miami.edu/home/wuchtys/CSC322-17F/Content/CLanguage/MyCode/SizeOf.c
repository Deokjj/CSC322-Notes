#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_STRING_LENGTH 128

typedef char String[MAX_STRING_LENGTH];
//-----------------------------------------------------------------------------
int main(void) {

    float MyFloat;
    unsigned long int BitPattern;

    printf("The size of char is %d\n",sizeof(char));
    printf("The size of int is %d\n",sizeof(int));
    printf("The size of short is %d\n",sizeof(short));
    printf("The size of long is %d\n",sizeof(long));
    printf("The size of float is %d\n",sizeof(float));
    printf("The size of double is %d\n",sizeof(double));
    printf("The size of long double is %d\n",sizeof(long double));
    printf("The size of String is %d\n",sizeof(String));
    printf("The size of 'A' is %d\n",sizeof('A'));
    printf("The size of (char)'A' is %d\n",sizeof((char)'A'));
    printf("The size of \"abcdefg\" is %d\n",sizeof("abcdefg"));
    printf("The size of MyFloat is %d\n",sizeof(MyFloat));
    printf("The size of BitPattern is %d\n",sizeof(BitPattern));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

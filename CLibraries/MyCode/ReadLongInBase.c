/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/
int main(int argc,char *argv[]) {

    if (argc != 3) {
        printf("Usage: ReadLongInBase <number> <base>\n");
        return(EXIT_FAILURE);
    }

    printf("%s base %d is %ld base 10\n",argv[1],atoi(argv[2]),
strtol(argv[1],NULL,atoi(argv[2])));

    return(EXIT_SUCCESS);
}
/*---------------------------------------------------------------------------*/


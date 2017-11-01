//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define SCREEN_WIDTH 80.0
#define SCREEN_HEIGHT 24
//-----------------------------------------------------------------------------
int main(void) {

    int Row,Column,Offset;

    srand(getpid());
    for (Row = 0; Row < SCREEN_HEIGHT; Row++) {
        Offset = rand()*SCREEN_WIDTH/RAND_MAX;
        for (Column = 0; Column < Offset; Column++) {
            putchar(' ');
        }
        printf("X\n");
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

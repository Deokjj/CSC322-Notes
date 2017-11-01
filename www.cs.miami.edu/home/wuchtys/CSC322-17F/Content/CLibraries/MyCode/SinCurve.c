//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
//-----------------------------------------------------------------------------
int main(void) {

    int Row,Column,Offset;
    double Angle;

    for (Row = 0; Row < SCREEN_HEIGHT; Row++) {
        Angle = 2 * M_PI * Row / (SCREEN_HEIGHT-1);
        Offset = floor((1+sin(Angle))*(SCREEN_WIDTH/2 - 1));
        for (Column = 0; Column < Offset; Column++) {
            putchar(' ');
        }
        printf("X\n");
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

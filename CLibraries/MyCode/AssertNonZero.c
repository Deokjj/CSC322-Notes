//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//-----------------------------------------------------------------------------
int main(void) {

    float Number,Total;

    printf("Enter the number of items, and their total value : ");
    scanf(" %f %f",&Number,&Total);

    assert(Number != 0.0);

    printf("The average is %.2f\n",Total/Number);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

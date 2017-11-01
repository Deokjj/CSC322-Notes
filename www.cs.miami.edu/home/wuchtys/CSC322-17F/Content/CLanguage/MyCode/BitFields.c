//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int Parity:1;
    unsigned int Middle:6;
    unsigned int Sign:1;
} ByteSplitType;

typedef union {
    signed char ByteInt;
    ByteSplitType Bits;
} OverlayType;
//-----------------------------------------------------------------------------
int main(void) {

    OverlayType MyByte;

    printf("Enter your integer : ");
    scanf("%hhi",&MyByte.ByteInt);
    printf("That is %d\n",MyByte.ByteInt);
    printf("The sign bit is %d\n",MyByte.Bits.Sign);
    printf("The middle bits are %d\n",MyByte.Bits.Middle);
    printf("The parity bit is %d\n",MyByte.Bits.Parity);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

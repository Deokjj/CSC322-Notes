//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

#define BIT(N) (1 << (N))
//-----------------------------------------------------------------------------
int CountBitsSet(int Number) {

    int BitsSet = 0;

    while (Number != 0) {
        if (Number & 1) {
            BitsSet++;
        }
        Number = Number >> 1;
    }

    return(BitsSet);
}
//-----------------------------------------------------------------------------
int main(void) {

    byte C1;
    int BitNumber;

    printf("Enter your integer in octal : ");
    scanf("%hho",&C1);

    printf("The integer is      %3d\n",C1);
    printf("The character is    \'%c\'\n",C1);
    printf("The last 3 bits are %3d\n",C1 & 07);
    printf("The bit pattern is  ");
    for (BitNumber = 7; BitNumber >= 0; BitNumber--) {
        printf("%d",(C1 & BIT(BitNumber)) != 0);
    }
    printf("\n");
    printf("The middle 4 bits are %3d\n",(C1 >> 2) & 017);
    printf("There are %d bits set\n",CountBitsSet(C1));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

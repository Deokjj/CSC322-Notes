/*---------------------------------------------------------------------------*/
#include <stdio.h>
/*---------------------------------------------------------------------------*/
unsigned invert(unsigned input,int position,int number) {

    return(input ^ (~(~0 << number) << position));
}
/*---------------------------------------------------------------------------*/
int main(void) {

    unsigned value;
    int position,number;

    printf("Enter hex value, position and number of bits to invert : ");
    scanf("%x %d %d",&value,&position,&number);
    printf("The result is %x\n",invert(value,position,number));

    return(0);
}
/*---------------------------------------------------------------------------*/

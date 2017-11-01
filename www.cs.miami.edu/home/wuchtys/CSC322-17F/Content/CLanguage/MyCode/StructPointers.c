//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int AnInt;
    float AFloat;
} IntAndFloatType;
//-----------------------------------------------------------------------------
int main(void) {

    IntAndFloatType ANicePair;
    IntAndFloatType *PointAtAPair;

    ANicePair.AnInt = 27;
    ANicePair.AFloat = -1.5;
    printf("1. The int part is %d and the float part is %f\n",ANicePair.AnInt,
ANicePair.AFloat);

    PointAtAPair = &ANicePair;
    printf("2. The int part is %d and the float part is %f\n",
(*PointAtAPair).AnInt,(*PointAtAPair).AFloat);
    printf("3. The int part is %d and the float part is %f\n",
PointAtAPair->AnInt,PointAtAPair->AFloat);
    
    PointAtAPair->AnInt = 16;
    printf("4. The int part is %d and the float part is %f\n",
PointAtAPair->AnInt,PointAtAPair->AFloat);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

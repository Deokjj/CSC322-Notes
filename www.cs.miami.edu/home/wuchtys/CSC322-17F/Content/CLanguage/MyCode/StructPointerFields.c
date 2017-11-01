//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *PointAtAnInt;
    float *PointAtAFloat;
} IntAndFloatType;
//-----------------------------------------------------------------------------
int main(void) {

    int AnInt;
    float AFloat;
    IntAndFloatType ANicePair;
    IntAndFloatType *PointAtAPair;

    AnInt = 27;
    AFloat = -1.5;
    printf("1. The int is %d and the float is %f\n",AnInt,AFloat);

    ANicePair.PointAtAnInt = &AnInt;
    ANicePair.PointAtAFloat = &AFloat;
    printf("2. The int is %d and the float is %f\n",*(ANicePair.PointAtAnInt),
*(ANicePair.PointAtAFloat));

    PointAtAPair = &ANicePair;
    printf("3. The int is %d and the float is %f\n",
*(PointAtAPair->PointAtAnInt),*(PointAtAPair->PointAtAFloat));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

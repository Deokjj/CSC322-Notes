#include <stdio.h>
#include <stdlib.h>

#define XOR(B1,B2) (!((B1)&&(B2)) && ((B1)||(B2)))
//-----------------------------------------------------------------------------
int main(void) {   

    int ImInTheShower,YoureInTheShower,ReasonableSituation;

    printf("Enter 1/0 for ImInTheShower and YoureInTheShower : ");
    scanf(" %d %d",&ImInTheShower,&YoureInTheShower);

    ReasonableSituation = XOR(ImInTheShower,YoureInTheShower);

    if (ReasonableSituation) {
        printf("Reasonable\n");
    }
    
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

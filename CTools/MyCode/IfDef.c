#include <stdio.h>
#include <stdlib.h>

#define XOR(B1,B2) ((!((B1)&&(B2))) && ((B1)||(B2)))
#define GOOD_FRIENDS
//-----------------------------------------------------------------------------
int main(void) {   

    int ImInTheShower,YoureInTheShower,ReasonableSituation;

    printf("Enter 1/0 for ImInTheShower and YoureInTheShower : ");
    scanf(" %d %d",&ImInTheShower,&YoureInTheShower);

#ifdef DEBUG
    printf("I'm in the shower : %d\n",ImInTheShower);
    printf("You're in the shower : %d\n",YoureInTheShower);
#endif

#ifdef GOOD_FRIENDS
    ReasonableSituation = ImInTheShower || YoureInTheShower;
#else
    ReasonableSituation = XOR(ImInTheShower,YoureInTheShower);
#endif

    if (ReasonableSituation) {
        printf("Clean and reasonable\n");
    }
    
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

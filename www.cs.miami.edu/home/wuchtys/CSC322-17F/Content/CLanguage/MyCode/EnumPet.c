//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128

typedef char String[MAX_STRING];

typedef enum {
    puppy,
    goldfish,
    albatross,
    rock,
    error
} PetType;
//-----------------------------------------------------------------------------
PetType InputPetType(void) {

    String Pet;

    scanf("%s",Pet);
    if (!strcmp(Pet,"puppy")) {
        return(puppy);
    }
    if (!strcmp(Pet,"goldfish")) {
        return(goldfish);
    }
    if (!strcmp(Pet,"albatross")) {
        return(albatross);
    }
    if (!strcmp(Pet,"rock")) {
        return(rock);
    }
    return(error);
}
//-----------------------------------------------------------------------------
char* StringPetType(PetType Pet) {

    switch (Pet) {
        case puppy:
            return("puppy");
            break;
        case goldfish:
            return("goldfish");
            break;
        case albatross:
            return("albatross");
            break;
        case rock:
            return("rock");
            break;
        default:
            return("error");
            break;
    }
}
//-----------------------------------------------------------------------------
int main(void) {

    PetType MyPet;

    printf("Please enter your pet type : ");
    MyPet = InputPetType();
    printf("You lucky fella, you own a %s\n",StringPetType(MyPet));
    printf("(and BTW, you have a wonderful integer %d)\n",MyPet);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];
typedef enum { false, true } boolean;
typedef enum { mammal, insect, bird, fish } AnimalType;
typedef struct {
  AnimalType type;
  double size;
  String name;
} Animal;

AnimalType getTypeFromString (String type) {
    if (strcmp(type, "mammal") == 0) {
        return mammal;
    } else if (strcmp(type, "insect") == 0) {
        return insect;
    } else if (strcmp(type, "bird") == 0) {
        return bird;
    } else if (strcmp(type, "fish") == 0) {
        return fish;
    } else {
        perror("invalid animal type. 'mammal', 'insect', 'bird' or 'fish'. Exiting");
        exit(-1);
    }
}

char * getStringFromType (AnimalType type) {
    switch (type) {
        case bird:      return "bird";
        case fish:      return "fish";
        case insect:    return "insect";
        case mammal:    return "mammal";
        default:        return "error";
    }
}

boolean enterAnimal (Animal * a) {
    String type;

    printf("Enter animal information (\"exit\" as name to exit)\n");

    printf("What is the name: ");
    scanf("%s", a->name);

    if (strcmp(a->name, "exit") == 0) {
        return false;
    }

    printf("What is the size: ");
    scanf("%lf", &a->size);

    printf("What is the type: ");
    scanf("%s", type);

    a->type = getTypeFromString(type);

    return true;
}

void makeRoom (Animal *** found, int * size) {
    *size *= 2; // Doubles its size
    *found = realloc(*found, *size * sizeof(Animal *));
    //realloc returns NULL if there is not enough memory available for new size
    if (*found == NULL) {
        perror("memory could not be reallocated. exiting.");
        exit(-1);
    }
}

void printAnimals (Animal ** found, int size) {
    int i;
    Animal * a;
    printf("The following new species were found:\n");
    for (i = 0; i < size; i++) {
        a = *(found + i);
        printf("%-15s has size %5.2f and is a %s\n", a->name, a->size, getStringFromType(a->type));
    }
}

int main (void) {
    int maxSize = 1, currentIndex = -1;
    //Initial mamory allocation for the size of one Animal pointer
    Animal ** found = malloc(sizeof(Animal *));

    while (true) {
        Animal * a = malloc(sizeof(Animal));
        if (++currentIndex >= maxSize) {
            makeRoom(&found, &maxSize);
        }
        if (!enterAnimal(a)) {
            break;
        } else {
            *(found + currentIndex) = a;            
        }
    }

    printAnimals(found, currentIndex);

    return 0;
}

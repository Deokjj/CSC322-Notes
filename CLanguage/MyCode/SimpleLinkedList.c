/*---------------------------------------------------------------------------*/
#include <stdio.h>

typedef struct LinkedNodeTag {
    int someData;
    struct LinkedNodeTag *nextNode;
} LinkedNode;

typedef LinkedNode *LinkedNodePointer;

#define SENTINEL -1
/*---------------------------------------------------------------------------*/
int main(void) {

    LinkedNodePointer head = NULL;
    LinkedNodePointer newNode;
    int userInput;

    printf("Please enter an integer, %d to end : ",SENTINEL);
    scanf(" %d",&userInput);
    while (userInput != SENTINEL) {
        newNode = (LinkedNodePointer)malloc(sizeof(LinkedNode));
        newNode->someData = userInput;
        newNode->nextNode = head;
        head = newNode;
        printf("Please enter an integer, %d to end : ",SENTINEL);
        scanf(" %d",&userInput);
    }

    printf("\nThe numbers are ");
    while (head != NULL) {
        printf("%d ",head->someData);
        newNode = head;
        head = head->nextNode;
        free(newNode);
    }

    printf("\n");
    
    return(EXIT_SUCCESS);
}
/*---------------------------------------------------------------------------*/

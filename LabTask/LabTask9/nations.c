#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 20

typedef char String[STRING_LENGTH];
typedef enum { false, true } bool;
typedef struct node {
    String name;
    struct node * next;
    struct node * bff;
} Node;

Node * findNameInList (Node * head, String name) {
    Node * current = head;

    while (current->next != NULL) {
        current = current->next;
        if (!strcmp(name, current->name)) return current; // return the node with the same name
    }
    return NULL; // return NULL if unique name
}

bool addNation (Node * head, Node * newNode) {
  printf("Enter nation name : ");
  scanf("%s", newNode->name);
  
  // if '-1' entered return false
  if (!strcmp(newNode->name, "-1")) {
    free(newNode);
    return false;
  } 
  
  // check if unique name
  while( findNameInList(head, newNode->name) != NULL ){
    printf("The same name already exists, please enter an unique name.");
    scanf("%s", newNode->name);
    if (!strcmp(newNode->name, "-1")) {
      free(newNode);
      return false;
    } 
  }
  // linking
  newNode->next = head->next;
  head->next = newNode;
  return true;
}

void addBestAlly(Node * head) {
  String nameOfBff;
  Node * foundNode = NULL;
  Node * current = head;
  
  while (current->next != NULL){
    current = current->next;
    
    while(true){
      printf("Enter best ally name for %s : ", current->name);
      scanf("%s",nameOfBff);
      
      foundNode = findNameInList(head, nameOfBff);
      //check if name of best ally is the same as current node's name
      if(!strcmp(current->name, nameOfBff)){
        printf("you entered the same name.");
      }
      //check if name exists in the list
      else if(foundNode == NULL){
        printf("%s does not exist in the list", nameOfBff);
      }
      //bestAlly found
      else{
        break;
      }
    }
    
    current->bff = foundNode;
  }
  
}

void printAndDeallocate (Node * head) {
  Node * current = head;
  while(current->next !=NULL){
    current = current->next;
    printf("The best ally of %s is %s. \n", current->name, current->bff->name);
    // deallocate the node previous to the current node
    free(head);
    // assign current node to head so it can be deallocated next iteration
    head = current; 
  }
  // free the last node.
  free(head);
}

int main(void) {
  Node * head = (Node*) malloc(sizeof(Node));
  head->next = NULL;
  
  printf("Enter '-1' when you are done entering nations.\n");
  
  while(addNation( head , malloc(sizeof(Node)) ));
  
  // exit if no nation entered
  if (head->next == NULL) {
    printf("\nyou didn't enter any nation. Exiting..\n");
    free(head);
    return -1;
  }
  // exit if only one nation entered
  if(head->next->next->name == NULL) {
    printf("\nonly one nation has been entered. No best ally is applicable. exiting..\n");
    return -1;
  }
  
  addBestAlly(head);
  
  printAndDeallocate(head);
  
  return 0;
}

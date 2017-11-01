//-----------------------------------------------------------------------------
//----This program counts the number of occurences of words on the
//----stdin stream and outputs the counts to stdout.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 20
//-----------------------------------------------------------------------------
//----String type definition
typedef char String[STRING_LENGTH];

//----List node type definition
typedef struct list_node {
    String Word;
    int Count;   
    struct list_node *Next;
} ListNodeType;

typedef ListNodeType *LISTNODE;
//-----------------------------------------------------------------------------
void * Malloc(size_t Size) {

    void * Memory;

    if ((Memory = malloc(Size)) == NULL) {
        perror("Cannot malloc");
        exit(EXIT_FAILURE);
    } else {
        return(Memory);
    }
}
//-----------------------------------------------------------------------------
void Free(void ** Memory) {

    free(*Memory);
    *Memory = NULL;
}
//-----------------------------------------------------------------------------
//---Print list
void PrintList(LISTNODE PrintHead) {

    while (PrintHead != NULL) {
        printf("%4d %s\n",PrintHead->Count,PrintHead->Word);
        PrintHead = PrintHead->Next;
    }
}
//-----------------------------------------------------------------------------
void FreeList(LISTNODE *FreeHead) {

    LISTNODE FreeThis;

    while (*FreeHead != NULL) {
        FreeThis = *FreeHead;
        FreeHead = &((*FreeHead)->Next);
        Free((void **)&FreeThis);
    }
}
//-----------------------------------------------------------------------------
//----Check if node is in list
LISTNODE InList(LISTNODE SearchHead,char *SearchWord) {

    while (SearchHead != NULL && strcmp(SearchHead->Word,SearchWord)) {
        SearchHead = SearchHead->Next;
    }
    return(SearchHead);
}
//-----------------------------------------------------------------------------
//----This adds a word into a list if it is new, or increments the count for 
//----the word if it already exists. Returns a pointer to the updated list.
void AddToList(LISTNODE *PointToHead,char *NewWord) {

    LISTNODE FoundAt;

    if ((FoundAt = InList(*PointToHead,NewWord)) != NULL) {
        FoundAt->Count++;
    } else {
//----New word in list
        FoundAt = (LISTNODE)Malloc(sizeof(ListNodeType));
        strcpy(FoundAt->Word,NewWord);
        FoundAt->Count = 1;
        FoundAt->Next = *PointToHead;
        *PointToHead = FoundAt;
    }
}
//-----------------------------------------------------------------------------
//----Count the occurences of each word on the stdin stream
int main(void) {

    LISTNODE Head;
    String Word;

//----Initialise the list to empty.
    Head = NULL;

//----Read words and others until EOF. If a word is read put it in the list.
    while (scanf("%s",Word) != EOF) {
        AddToList(&Head,Word);
    }

//----Print the tree generated.
    PrintList(Head);

//----Free the list
    FreeList(&Head);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

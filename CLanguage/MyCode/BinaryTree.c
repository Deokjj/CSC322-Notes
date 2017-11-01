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

//----Tree node type definition
typedef struct tree_node {
    char *Word;
    int Count;
    struct tree_node *Left;
    struct tree_node *Right;
    } TreeNodeType;

typedef TreeNodeType *TREENODE;
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
//----This adds a word into a tree if it is new, or increments the count for 
//----the word if it already exists. Returns a pointer to the updated tree.
TREENODE AddToTree(TREENODE Root,char *Word) {

    int Comparison;

//----If this tree is empty then create a new node and return a pointer to it.
    if (Root == NULL) {
//----New word in tree
        Root = (TREENODE) Malloc(sizeof(TreeNodeType));
        Root->Word = strcpy((char *) Malloc(strlen(Word)+1),Word);
        Root->Count = 1;
        Root->Left = NULL;
        Root->Right = NULL;
    } else if ((Comparison = strcmp(Word,Root->Word)) == 0) {
//----If not an empty tree check if this node contains the word, or
//----which sub-tree it should be in.
//----Repeated word so increment count
        Root->Count++;
    } else if (Comparison < 0) {
//----Lower goes in left subtree, greater in right. Call recursively
//----with the appropriate sub-tree. 
        Root->Left = AddToTree(Root->Left,Word);
    } else {
        Root->Right = AddToTree(Root->Right,Word);
    }

//----Return the updated sub-tree (tree) to the previous level. This
//----will often not change anything.
    return(Root);
}
//-----------------------------------------------------------------------------
//---Print tree recursively in infix order
void PrintTree(TREENODE Root) {

//----If not outside the tree print left, self then right.
    if (Root != NULL) {
        PrintTree(Root->Left);
        printf("%4d %s\n",Root->Count,Root->Word);
        PrintTree(Root->Right);
    }
}
//-----------------------------------------------------------------------------
//----Count the occurences of each word on the stdin stream
int main(void) {

    TREENODE Root;
    String Word;

//----Initialise the tree to empty.
    Root = NULL;

//----Read words and others until EOF. If a word is read put it in the tree.
    while (scanf("%s",Word) != EOF) {
        Root = AddToTree(Root,Word);
    }

//----Print the tree generated.
    PrintTree(Root);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

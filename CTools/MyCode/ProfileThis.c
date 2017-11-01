//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
typedef struct FibonacciNode {
    long Value;
    struct FibonacciNode * Next;
} FibonacciNodeType;

typedef FibonacciNodeType * FIBONACCINODE;
//-----------------------------------------------------------------------------
long LinearFibonacci(int Number) {

    long Previous = 0;
    long Current = 1;
    long Next;

    if (Number <= 2) {
        return(Number-1);
    }

    while (Number > 2) {
        Next = Previous + Current;
        Previous = Current;
        Current = Next;
        Number--;
    }
    return(Current);

}
//-----------------------------------------------------------------------------
long QuadraticFibonacci(int Number) {

    FIBONACCINODE Head;
    FIBONACCINODE NewNode;
    FIBONACCINODE Iterator;

    Head = (FIBONACCINODE)malloc(sizeof(FibonacciNodeType));
    NewNode = (FIBONACCINODE)malloc(sizeof(FibonacciNodeType));
    Head->Value = 0;
    Head->Next = NewNode;
    Head->Next->Value = 1;
    Head->Next->Next = NULL;

    while (Number > 2) {
        Iterator = Head;
        while (Iterator->Next->Next != NULL) {
            Iterator = Iterator->Next;
        }
        NewNode = (FIBONACCINODE)malloc(sizeof(FibonacciNodeType));
        NewNode->Next = NULL;
        NewNode->Value = Iterator->Value + Iterator->Next->Value;
        Iterator->Next->Next = NewNode;
        Number--;
    }
    Iterator = Head;
    while (Iterator->Next != NULL) {
        Iterator = Iterator->Next;
    }
    return(Iterator->Value);
}
//-----------------------------------------------------------------------------
long ExponentialFibonacci(int Number) {

    if (Number <= 2) {
        return(Number-1);
    } else {
        return(ExponentialFibonacci(Number-1) + ExponentialFibonacci(Number-2));
    }
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int Number;

    Number = atoi(argv[1]);
    printf("LinearFibonacci(%2d)      = %ld\n",Number,LinearFibonacci(Number));
    printf("QuadraticFibonacci(%2d)   = %ld\n",Number,QuadraticFibonacci(Number));
    printf("ExponentialFibonacci(%2d) = %ld\n",Number,ExponentialFibonacci(Number));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//----File: main.c
//----Description:  Use the greet module to display the greeting "Hello world"
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

extern void Greet(char *Greeting);
//-----------------------------------------------------------------------------
int main(void) {

    Greet("Hello world.");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

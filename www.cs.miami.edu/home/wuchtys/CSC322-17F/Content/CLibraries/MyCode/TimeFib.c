//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//-----------------------------------------------------------------------------
//----Function to compute the Nth Fibonacci number recursively
long Fibonacci(long WhichNumber) {

//----If the 1st or second number, return the answer directly
    if (WhichNumber <= 1) {
        return(WhichNumber);
//----Otherwise return the sum of the previous two Fibonacci numbers
    } else {
        return(Fibonacci(WhichNumber - 2) + Fibonacci(WhichNumber - 1));
    }
}
//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {

    long WhichNumber;
    long Answer;
    clock_t Start,End;

    WhichNumber = atol(argv[1]);
    Start = clock();
    Answer = Fibonacci(WhichNumber);
    End = clock();
    printf("The %ld Fibonacci number is %ld\n",WhichNumber,Answer);
    printf("That took %.2f seconds to compute\n",
((double)(End-Start))/CLOCKS_PER_SEC);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

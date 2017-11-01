//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <setjmp.h>
#include <math.h>
//-----------------------------------------------------------------------------
void RandomNotDiv(int BadDivisor,int NumberLeftToGenerate,
jmp_buf Environment) {

    static int Random;

    if (NumberLeftToGenerate == 0) {
        printf("\n");
        return;
    } else {
        Random = rand();
        printf("%d ",Random);
        if (Random % BadDivisor == 0) {
            printf(" divisible by %d\n",BadDivisor);
            longjmp(Environment,NumberLeftToGenerate);
        } else {
            RandomNotDiv(BadDivisor,--NumberLeftToGenerate,Environment);
        }
    }
}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int WantToGenerate = atoi(argv[1]);
    int BadDivisor = atoi(argv[2]);
    int NumberLeftToGenerate;
    jmp_buf Environment;

    srand(getpid());
    if ((NumberLeftToGenerate = setjmp(Environment)) == 0) {
        RandomNotDiv(BadDivisor,WantToGenerate,Environment);
        printf("Hoorah, generated %d random numbers not divisible by %d\n",
WantToGenerate,BadDivisor);
    } else {
        printf("Boohoo, generated %d random numbers not divisible by %d\n",
WantToGenerate-NumberLeftToGenerate,BadDivisor);
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

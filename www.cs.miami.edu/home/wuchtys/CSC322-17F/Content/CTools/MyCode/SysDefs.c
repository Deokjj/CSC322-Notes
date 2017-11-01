#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int main(void) {

    printf("line %d, file %s, date %s, time %s\n",__LINE__,__FILE__,
__DATE__,__TIME__);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

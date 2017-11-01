#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(void) {

    printf("The real user of this process has ID %d\n",getuid());
    printf("The effective user of this process has ID %d\n",geteuid());
    printf("The real user group ID for this process is %d\n",getgid());
    printf("The effective user group for this process is %d\n",getegid());

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

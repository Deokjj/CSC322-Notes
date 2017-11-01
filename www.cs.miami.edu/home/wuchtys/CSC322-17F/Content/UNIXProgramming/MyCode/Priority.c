#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    printf("The priority of this process is %d\n",getpriority(PRIO_PROCESS,0));
    if (setpriority(PRIO_PROCESS,0,atoi(argv[1])) == -1) {
        perror("Changing priority");
    }
    printf("The new priority of this process is %d\n",
getpriority(PRIO_PROCESS,0));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

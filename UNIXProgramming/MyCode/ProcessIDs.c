#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
int main(void) {

    printf("This is process number %d\n",getpid());
    printf("This process is in group number %d\n",getpgid(0));
    printf("The parent process is number %d\n",getppid());
    printf("The parent process is in group number %d\n",getpgid(getppid()));
    if (setpgid(0,getpgid(getppid())) != 0) {
        perror("Cannot set process group number");
    }
    printf("The new process group number is %d\n",getpgid(0));

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

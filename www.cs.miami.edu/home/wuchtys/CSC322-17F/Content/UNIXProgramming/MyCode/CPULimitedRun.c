//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//-----------------------------------------------------------------------------
void SetCPUTimeLimit(int CPUTimeLimit) {

    struct rlimit ResourceLimits;

//----Limit the CPU time. Need to get old one for hard limit field
    if (getrlimit(RLIMIT_CPU,&ResourceLimits) == -1) {
        perror("CPULimitedRun - Getting resource limit:");
        exit(EXIT_FAILURE);
    }
//----Set new CPU limit in ms (sent in secs)
    ResourceLimits.rlim_cur = CPUTimeLimit-1; //---- -1 because its weird
    if (setrlimit(RLIMIT_CPU,&ResourceLimits) == -1) {
        perror("CPULimitedRun - Setting resource limit:");
        exit(EXIT_FAILURE);
    }
}
//-----------------------------------------------------------------------------
int main(int NumberOfArguments,char *Arguments[]) {

    int TimeLimit;
    int ChildPID;
    int Status;
    struct rusage Usage;

//----Execute the ATP system
    if ((ChildPID = fork()) == -1) {
        perror("Could not fork");
        exit(EXIT_FAILURE);
    }

    if (ChildPID == 0) {
        TimeLimit = atoi(Arguments[1]);
        SetCPUTimeLimit(TimeLimit);
        execvp(Arguments[2],Arguments+2);
        perror("CPULimitedRun - Cannot exec program:");
        exit(EXIT_FAILURE);
    } else {
        waitpid(ChildPID,&Status,0);
        if (WIFSIGNALED(Status)) {
            printf("The child ran out of CPU time\n");
        } else {
            getrusage(RUSAGE_CHILDREN,&Usage);
            printf("The child used %lds %ldms\n",
Usage.ru_utime.tv_sec+Usage.ru_stime.tv_sec,
Usage.ru_utime.tv_usec+Usage.ru_stime.tv_usec);
        }
    }

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

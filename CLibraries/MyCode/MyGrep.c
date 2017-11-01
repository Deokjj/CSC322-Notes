//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    regex_t CompiledRegExp;

    if (argc != 3) {
        printf("Usage %s <regexp> <string>\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    if (regcomp(&CompiledRegExp,argv[1],REG_EXTENDED) != 0) {
        printf("ERROR: Something wrong in the regular expression\n");
        exit(EXIT_FAILURE);
    }

    if (regexec(&CompiledRegExp,argv[2],0,NULL,0) == 0) {
        printf("Yes, it's there\n");
    } else {
        printf("No, it's not there\n");
    }

    regfree(&CompiledRegExp);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

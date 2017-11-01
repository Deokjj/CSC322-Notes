//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
//-----------------------------------------------------------------------------
void DisplayPasswdEntry(struct passwd *PasswdEntry) {

    printf("User %10s (UID = %4d) with password %10s uses %s\n",
PasswdEntry->pw_name,PasswdEntry->pw_uid,
PasswdEntry->pw_passwd,PasswdEntry->pw_shell);

}
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    struct passwd *PasswdEntry;

//----Of no command line argument, then list all entries
    if (argc == 1) {
        while ((PasswdEntry = getpwent()) != NULL) {
            DisplayPasswdEntry(PasswdEntry);
        }
        endpwent();
        return(EXIT_SUCCESS);
    }

    if (argc == 2) {
//----Try a name
        if ((PasswdEntry = getpwnam(argv[1])) != NULL) {
            DisplayPasswdEntry(PasswdEntry);
//----Try a UID
        } else if ((PasswdEntry = getpwuid(atoi(argv[1]))) != NULL) {
            DisplayPasswdEntry(PasswdEntry);
        } else {
            printf("%s is not a valid name or UID\n",argv[1]);
        }
        return(EXIT_SUCCESS);
    }

    printf("Invalid usage\n");
    return(EXIT_FAILURE);
       
}
//-----------------------------------------------------------------------------

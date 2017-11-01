//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

#define SALT_LENGTH 2
//-----------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    char *Password;
    char *Encrypted;
    char Salt[SALT_LENGTH+1];

    Password = getpass("Enter your password: ");
    printf("Enter your salt: ");
    fgets(Salt,SALT_LENGTH+1,stdin);
    Encrypted = crypt(Password,Salt);
    memset(Password,'\0',strlen(Password));

    printf("The encrypted password is %s\n",Encrypted);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

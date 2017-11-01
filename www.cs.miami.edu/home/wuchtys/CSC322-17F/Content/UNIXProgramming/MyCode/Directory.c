//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
//-----------------------------------------------------------------------------
int main(int argc,char* argv[]) {

    struct dirent *DirectoryEntry;
    DIR *DirectoryStream;

    if ((DirectoryStream = opendir(argv[1])) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((DirectoryEntry = readdir(DirectoryStream)) != NULL) {
        printf("%s\n",DirectoryEntry->d_name);
    }

    closedir(DirectoryStream);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------

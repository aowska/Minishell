#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void)
{
    DIR *dirp;
    struct dirent *direntp;
	//path;
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
    dirp = opendir(cwd);
    if (dirp == NULL)
    {
        perror("can't open ");
		printf("%s",cwd);
        return EXIT_FAILURE;
    }
    else
    {
        while ((direntp = readdir(dirp)) != NULL)
        {
            // Pomijamy pliki i katalogi zaczynające się od "."
            if (direntp->d_name[0] != '.')
            {
                printf("%s", direntp->d_name);
            }
        }

        closedir(dirp);
    }

    return EXIT_SUCCESS;
}
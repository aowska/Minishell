#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fd_cd(char **args)
{
	 char cwd[1024];
	if (args[1] == NULL)
	{
		getcwd(cwd, sizeof(cwd));
	}
	else if (chdir(args[1]) != 0)
	{
		perror("fd_cd: błąd przy zmianie katalogu");
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	// Przekazujemy argumenty do funkcji fd_cd
	if (fd_cd(argv) != 0)
	{
		fprintf(stderr, "Nie udało się zmienić katalogu\n");
		return EXIT_FAILURE;
	}

	// Wypisujemy nowy katalog roboczy
	char *cwd = getenv("PWD");
	if (cwd != NULL)
	{
		printf("Nowy katalog roboczy: %s\n", cwd);
	}
	else
	{
		fprintf(stderr, "Nie można odczytać nowego katalogu roboczego\n");
	}

	return EXIT_SUCCESS;
}
#include "minishell.h"

// Funkcja obsługująca "cd"
int	ft_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "minishell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("minishell");
		}
	}
	return (1);
}

// Funkcja obsługująca "pwd"
int	ft_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("minishell");
	}
	return (1);
}

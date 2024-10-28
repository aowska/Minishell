#include "minishell.h"

// Global for the exit status
int g_exit_status = 0;

char *remove_input_part(char *input)
{
	char	*space;
	int		length;
	char	*result;
	char	*start_quote;
	char	*end_quote;

	space = ft_strchr(input, ' ');
	if (space == NULL)
	{
		return (input);
	}
	length = ft_strlen(space + 1);
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, space + 1);
	start_quote = ft_strchr(result, '"');
	if (start_quote)
		ft_memmove(start_quote, start_quote + 1, ft_strlen(start_quote));
	end_quote = ft_strrchr(result, '"');
	if (end_quote)
		*end_quote = '\0';
	return (result);
}

int main(void)
{
	char *input;
	char **args;
	char *commend;

	setup_signal_handlers();

	while (1)
	{
		input = readline("minishell> ");
		if (input == NULL)
		{
			ft_printf("exit\n");
			break;
		}
		if (*input)
			add_history(input);
		args = ft_split(input, ' ');
		commend = remove_input_part(input);
		if (args[0])
		{
			if (strcmp(args[0], "echo") == 0)
			{
				// fd_echo();
				printf("%s\n", commend);
			}
		}
		free(input);
		free(args);
	}

	return (0);
}

#include "minishell.h"
//Global
int g_exit_status = 0;

int main(void)
{
	char *input;
	char **args;

	// signal set up
	setup_signal_handlers();

	while (1)
	{
		// view prompt
		input = readline("minishell> ");

		// czek if user end program
		if (input == NULL)
		{
			printf("exit\n");
			break;
		}

		// add history
		if (*input)
			add_history(input);

		// Parsing comments 
		args = parse_input(input);

		// execute eommends 
		if (args[0])
		{
			if (strcmp(args[0], "cd") == 0)
				ft_cd(args);
			else if (strcmp(args[0], "exit") == 0)
			{
				free(input);
				free(args);
				break;
			}
			else
				execute_command(args); //exectue for example ls 
		}

		//free memory
		free(input);
		free(args);
	}

	return g_exit_status;
}

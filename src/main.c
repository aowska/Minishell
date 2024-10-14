#include "includes/minishell.h"
// Zmienna globalna do przechowywania statusu wyjścia komendy
int g_exit_status = 0;

int main(void)
{
	char *input;
	char **args;

	// Ustawiamy obsługę sygnałów (np. Ctrl+C)
	setup_signal_handlers();

	while (1)
	{
		// Wyświetlenie promptu i odczytanie inputu
		input = readline("minishell> ");

		// Sprawdzenie czy użytkownik zakończył (np. Ctrl+D / EOF)
		if (input == NULL)
		{
			printf("exit\n");
			break;
		}

		// Dodanie komendy do historii (dla strzałki w górę/dół)
		if (*input)
			add_history(input);

		// Parsowanie komendy (rozdzielenie na argumenty)
		args = parse_input(input);

		// Wykonywanie komend wbudowanych, jak "cd" czy "exit"
		if (args[0])
		{
			if (ft_strcmp(args[0], "cd") == 0)
				ft_cd(args);
			else if (ft_strcmp(args[0], "exit") == 0)
			{
				free(input);
				free(args);
				break;
			}
			else
				execute_command(args); // Wykonywanie innych komend (np. ls)
		}

		// Zwolnienie pamięci po każdej komendzie
		free(input);
		free(args);
	}

	return g_exit_status;
}

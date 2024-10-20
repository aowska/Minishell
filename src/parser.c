
#include "minishell.h"

// Funkcja parsująca input na tokeny
char **parse_input(char *input)
{
	int bufsize = TOKEN_SIZE;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, DELIMITERS);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += TOKEN_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("minishell");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIMITERS);
	}
	tokens[i] = NULL; // Koniec tablicy tokenów
	return tokens;
}

// Funkcja do zwolnienia pamięci
void free_tokens(char **tokens)
{
	free(tokens);
}

// Funkcja usuwająca białe znaki z początku i końca inputu
char *trim_whitespace(char *str)
{
	char *end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return str;

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';

	return str;
}

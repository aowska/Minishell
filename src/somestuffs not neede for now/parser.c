
#include "minishell.h"

// parsing input to token
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
	tokens[i] = NULL; // End token table
	return tokens;
}

//free memory
void free_tokens(char **tokens)
{
	free(tokens);
}

// white sings in baggining and end
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

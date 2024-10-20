#include "minishell.h"

void sigint_handler(int sig)
{
	(void)sig;
	printf("\nminishell> "); // View prompt after Ctrl+C
	fflush(stdout);
}

void setup_signal_handlers(void)
{
	signal(SIGINT, sigint_handler); // SIGINT (Ctrl+C)
}

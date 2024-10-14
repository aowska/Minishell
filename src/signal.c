#include "minishell.h"

void sigint_handler(int sig)
{
    (void)sig;
    printf("\nminishell> ");  // Wyświetl prompt po Ctrl+C
    fflush(stdout);
}

void setup_signal_handlers(void)
{
    signal(SIGINT, sigint_handler);  // Ustawienie handlera dla SIGINT (Ctrl+C)
}

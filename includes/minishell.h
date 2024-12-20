#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft.h"
# include "./ft_printf.h"
# include <stdlib.h>			   // malloc, free, exit
# include <unistd.h>			   /*ork, execve, access, pipe, dup2, write, read, chdir*/
# include <sys/wait.h>		   // wait, waitpid
# include <sys/types.h>		   // stat, lstat
# include <sys/stat.h>		   // stat, lstat, fstat
# include <fcntl.h>			   // open, close
# include <string.h>			   // strerror
# include <dirent.h>			   // opendir, readdir, closedir
# include <signal.h>			   // signal, sigaction
# include <errno.h>			   // errno
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>		   // bool type

// Definicje stałych
#define TOKEN_SIZE 64
#define DELIMITERS " \t\r\n\a"

// Funkcje główne
char	**fft_split(const char *str);
int		fd_echo(char *command);
void	setup_signal_handlers(void);
void	execute_command(char **args);
void	execute_pipe(char **args1, char **args2);
void execute_redirection(char **args, char *filename);

// Funkcje wbudowane (built-in)
int ft_cd(char **args);
int ft_exit(char **args);
int ft_pwd(void);

// Funkcje pomocnicze (utility)
char **parse_input(char *input);
char **split_by_pipe(char *input);
char **split_by_redirect(char *input, char delimiter);
char *trim_whitespace(char *str);
void free_tokens(char **tokens);



// Obsługa sygnałów
void sigint_handler(int sig);

// Struktura do zarządzania sygnałami (jeśli używasz struktur)
typedef struct s_minishell
{
	char **envp;
	int last_exit_status;
} t_minishell;

#endif

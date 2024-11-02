
#include "minishell.h"

void execute_command(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork(); // child process
	if (pid == 0) 
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("minishell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) //error
	{
		perror("minishell");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED); 
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

// pipe function 
void execute_pipe(char **args1, char **args2)
{
	int pipefd[2];
	pid_t pid1, pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return;
	}

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(args1[0], args1, NULL);
		perror("minishell");
		exit(EXIT_FAILURE);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		close(pipefd[0]);
		execve(args2[0], args2, NULL);
		perror("minishell");
		exit(EXIT_FAILURE);
	}

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}


void execute_redirection(char **args, char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return;
	}

	pid_t pid = fork();
	if (pid == 0) 
	{
		dup2(fd, STDOUT_FILENO); 
		close(fd);
		execve(args[0], args, NULL);
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	close(fd);
}

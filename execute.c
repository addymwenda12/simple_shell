#include "shell.h"

/**
 * execute_commands - Executes other commands in shell program
 * @cmd_argv: Argument vector for commands
 * @envp: Array that store environment variables
 *
 */

void execute_commands(char *cmd_argv[], char *envp[])
{
	char *filepath;
	int status;

	pid_t pid;

	if (cmd_argv[0][0]  == '/')
	{
		filepath = cmd_argv[0];
	}
	else
	{
		filepath = search_path(cmd_argv[0], envp);

		if (filepath == NULL)
		{
			write(STDOUT_FILENO, cmd_argv[0], my_strlen(cmd_argv[0]));
			write(STDOUT_FILENO, ": command not found\n", 20);
			return;
		}
	}

	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(filepath, cmd_argv, envp) == -1)
		{
			perror("execve failed");
			exit(1);
		}
	}
	else
	{
		do {
			if (waitpid(pid, &status, 0) != pid)
			{
				perror("waitpid failed");
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (cmd_argv[0][0] != '/')
	{
		free(filepath);
	}
}

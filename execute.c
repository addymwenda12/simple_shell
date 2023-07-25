#include "shell.h"

/**
 * get_file_path - Returns the full file path for a command
 * @cmd: The command to search for in the PATH
 * @envp: Array that stores environment variables
 *
 * Return: The full file path for the command if found,
 * or NULL if not found
 */

char *get_file_path(char *cmd, char *envp[])
{
	char *filepath;

	if (cmd == NULL || envp == NULL)
	{
		return (NULL);
	}

	if (cmd[0] == '/')
	{
		filepath = cmd;
	}
	else
	{
		filepath = search_path(cmd, envp);

		if (filepath == NULL)
		{
			write(STDOUT_FILENO, cmd, my_strlen(cmd));
			write(STDOUT_FILENO, ": command not found\n", 20);
			return (NULL);
		}
	}

	return (filepath);
}

/**
 * execute_child - Executes the child process using execve
 * @filepath: The full file path for the command
 * @cmd_argv: Argument vector for the command
 * @envp: Array that stores environment variables
 */

void execute_child(char *filepath, char *cmd_argv[],
		char *envp[])
{
	if (execve(filepath, cmd_argv, envp) == -1)
	{
		perror("execve failed");
		exit(1);
	}
}

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

	filepath = get_file_path(cmd_argv[0], envp);

	if (filepath != NULL)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}

		if (pid == 0)
		{
			execute_child(filepath, cmd_argv, envp);
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
}

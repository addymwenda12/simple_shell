#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: The argument count for the program
 * @argv: The argument vector for the shell
 * @envp: The evironment variable
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	char *cmd = NULL;
	char *cmd_argv[2];
	size_t len = 0;
	ssize_t read;
	int status;
	bool from_pipe = false;

	pid_t pid;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO == 0))
			from_pipe = true;

		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&cmd, &len, stdin);

		if (read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (cmd[strlen(cmd) - 1] == '\n')
		{
			cmd[strlen(cmd) - 1] = '\0';
		}

		cmd_argv[0] = cmd;
		cmd_argv[1] = NULL;

		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}

		if (pid == 0)
		{
			execve(cmd, cmd_argv, envp);
			perror("execve failed");
			exit(1);
		}
		else
		{
			if (waitpid(pid, &status, 0) != pid)
			{
				perror("waitpid failed");
			}
		}
	}

	free(cmd);
	return (0);
}

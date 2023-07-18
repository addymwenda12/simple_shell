#include "shell.h"

/**
 * main - Entry point of the program
 * @argc: The argument count for the program
 * @argv: The argument vector for the shell
 * @envp: The evironment variable
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[], char *PATH)
{
	char *cmd = NULL;
	char *cmd_argv[64];
	size_t len = 0;
	ssize_t read;
	int status;
	bool from_pipe = false;
	char *filepath;

	pid_t pid;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			from_pipe = true;
		}
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


		tokenize_path(PATH);

		filepath = search_path(cmd_argv[0], envp);
		if (filepath == NULL)
		{
			write(STDOUT_FILENO, cmd_argv[0], strlen(cmd_argv[0]));
			write(STDOUT_FILENO, ": command not found\n", 20);
			continue;
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

		free(filepath);
	}

	free(cmd);
	return (0);
}

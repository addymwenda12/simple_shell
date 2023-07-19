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
	char *cmd_argv[64];
	size_t len = 0;
	char *path;
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


		tokenize(cmd, cmd_argv);

		if (str_compare(cmd_argv[0], "exit") == 0)
		{
			status = 0;

			if (cmd_argv[1] != NULL)
			{
				status = str_to_int(cmd_argv[1]);
			}

			free(cmd);
			exit(status);
		}

		else if (str_compare(cmd_argv[0], "setenv") == 0)
		{
			if (cmd_argv[1] != NULL && cmd_argv[2] != NULL)
			{
				_setenv(cmd_argv[1], cmd_argv[2], 1);
			}
			else
			{
				write(STDERR_FILENO, "setenv: missing arguments\n", 26);
			}
		}

		else if (str_compare(cmd_argv[0], "unsetenv") == 0)
		{
			if (cmd_argv[1] != NULL)
			{
				_unsetenv(cmd_argv[1]);
			}
			else
			{
				write(STDERR_FILENO, "unsetenv: missing argument\n", 27);
			}
		}

		else if (str_compare(cmd_argv[0], "cd") == 0)
		{
			path = cmd_argv[1];

			if (path == NULL)
			{
				path = getenv("HOME");
			}
			else if (str_compare(path, "-") == 0)
			{
				path = getenv("OLDPWD");
			}
			
			if (_cd(path) == -1)
			{
				write(STDERR_FILENO, "cd: can't cd to ", 16);
				write(STDERR_FILENO, path, strlen(path));
				write(STDERR_FILENO, "\n", 1);
			}
		}

		if (cmd_argv[0][0] == '/')
		{
			filepath = cmd_argv[0];
		}
		else
		{
			filepath = search_path(cmd_argv[0], envp);
			if (filepath == NULL)
			{
				write(STDOUT_FILENO, cmd_argv[0], strlen(cmd_argv[0]));
				write(STDOUT_FILENO, ": command not found\n", 20);
				continue;
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

	free(cmd);
	return (0);
}

/**
 * tokenize - Use to tokenize array of strings
 * @cmd: Command string to be used
 * @cmd_argv: Array of string to be tokenized
 *
 * Return: The tokenized string
 */

void tokenize(char *cmd, char *cmd_argv[])
{
	char *token;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		cmd_argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	cmd_argv[i] = NULL;
}

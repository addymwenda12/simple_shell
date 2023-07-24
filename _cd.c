#include "shell.h"

/**
 * _cd - Change the current directory
 * @path: The new path
 *
 * Return: 0 on success, -1 on error
 */

int _cd(char *path)
{
	char cwd[1024];

	if (chdir(path) == -1)
	{
		perror("cd failed");
		return (-1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (-1);
	}
	return (_setenv("PWD", cwd, 1));
}

/**
 * handle_cd - Handles cd command
 * @cmd_argv: Command argument for cd
 *
 */

void handle_cd(char *cmd_argv[])
{
	char *path = cmd_argv[1];

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
		write(STDERR_FILENO, path, my_strlen(path));
		write(STDERR_FILENO, "\n", 1);
	}
}

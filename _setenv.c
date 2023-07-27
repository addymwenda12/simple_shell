#include "shell.h"

/**
 * _setenv - Set an environment variable
 * @name: Name of the variable
 * @value: Value of the variable
 * @overwrite: Whether to overwrite if the variable exists
 *
 * Return: 0 on success, -1 on error
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	if (setenv(name, value, overwrite) == -1)
	{
		perror("setenv failed");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @name: Name of the variable
 *
 * Return: 0 on success, -1 on error
 */

int _unsetenv(const char *name)
{
	if (unsetenv(name) == -1)
	{
		perror("unsetenv failed");
		return (-1);
	}
	return (0);
}

/**
 * handle_setenv - Handles addition of env variable
 * @cmd_argv: Argument vector of set env
 *
 */

void handle_setenv(char *cmd_argv[])
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

/**
 * handle_unsetenv - Handles removal of env variable
 * @cmd_argv: Argument vector for unset env
 *
 */

void handle_unsetenv(char *cmd_argv[])
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

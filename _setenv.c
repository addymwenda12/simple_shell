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

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

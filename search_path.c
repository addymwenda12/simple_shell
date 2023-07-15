#include "shell.h"

/**
 * search_path - Function that search path
 * @cmd: Command to be checked if found in the path
 * @envp: The environment variable
 *
 * Return: NULL if command found
 */

char *search_path(char *cmd, char **envp)
{
	char *PATH = getenv("PATH");
	char *p = strtok(PATH, ":");
	char *filepath = malloc(1024);
	char *temp, *temp_cmd;

	while (p != NULL)
	{
		temp = filepath;

		while ((*temp++ = *p++))
			;

		temp[-1] = '/';
		temp_cmd = cmd;

		while ((*temp++ = *temp_cmd++))
			;

		if (access(filepath, F_OK) != -1)
		{
			return (filepath);
		}
		p = strtok(NULL, ":");
	}

	free(filepath);
	return (NULL);
}

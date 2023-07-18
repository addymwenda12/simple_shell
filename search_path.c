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
	char **paths = tokenize_path(PATH);
	char *filepath = malloc(1024);
	char *temp, *temp_cmd;
	char *p;
	int i = 0;

	while (paths[i] != NULL)
	{
		temp = filepath;
		p = paths[i];

		while ((*temp++ = *p++))
			;

		temp[-1] = '/';
		temp_cmd = cmd;

		while ((*temp++ = *temp_cmd++))
			;

		if (access(filepath, F_OK) != -1)
		{
			free(paths);
			return (filepath);
		}
		i++;
	}

	free(paths);
	free(filepath);
	return (NULL);
}

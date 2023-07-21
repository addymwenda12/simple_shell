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
	char **paths;
	char *PATH_copy;
	char *filepath = malloc(1024);
	char *temp, *temp_cmd;
	char *p;
	int i = 0;

	if (PATH == NULL)
	{
		perror("Failed to get PATH");
		exit(EXIT_FAILURE);
	}

	PATH_copy =  my_strdup(PATH);
	paths = tokenize_path(PATH_copy);

	if (filepath == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

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

		if (access(filepath, X_OK) != -1)
		{
			free(paths);
			free(PATH_copy);
			return (filepath);
		}
		i++;
	}

	free(paths);
	free(PATH_copy);
	free(filepath);
	return (NULL);
}

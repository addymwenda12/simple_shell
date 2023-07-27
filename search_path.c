#include "shell.h"

/**
 * get_path - Gets the path of shell
 * @envp: Environment variable
 *
 * Return: The path of the shell
 */

char *get_path(char **envp)
{
	char *PATH = my_getenv("PATH", envp);

	if (PATH == NULL)
	{
		perror("Failed to get PATH");
		exit(EXIT_FAILURE);
	}

	return (my_strdup(PATH));
}

/**
 * create_filepath - Creates the filepath for shell
 * @path: The path for shell
 * @cmd: Command to be used
 *
 * Return: The filepath of shell
 */

char *create_filepath(char *path, char *cmd)
{
	char *filepath = malloc(1024);
	char *temp, *temp_cmd;
	char *p;

	if (filepath == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	temp = filepath;
	p = path;

	while ((*temp++ = *p++))
		;

	temp[-1] = '/';
	temp_cmd = cmd;

	while ((*temp++ = *temp_cmd++))
		;

	return (filepath);
}

/**
 * search_path - Function that search path
 * @cmd: Command to be checked if found in the path
 * @envp: The environment variable
 *
 * Return: NULL if command found
 */

char *search_path(char *cmd, char **envp)
{
	char *PATH_copy;
	char **paths;
	char *filepath;
	int i = 0;

	(void)envp;

	PATH_copy = get_path(envp);
	paths = tokenize_path(PATH_copy);

	while (paths[i] != NULL)
	{
		filepath = create_filepath(paths[i], cmd);

		if (access(filepath, X_OK) != -1)
		{
			free(paths);
			free(PATH_copy);
			return (filepath);
		}

		free(filepath);
		i++;
	}
	free(paths);
	free(PATH_copy);
	return (NULL);
}

#include "shell.h"

/**
 * my_getenv - Get the value of an environment variable
 * @name: Name of the environment
 * @envp: The environment variable
 *
 * Return: NULL if environment function fails
 */

char *my_getenv(char *name, char **envp)
{
	size_t len = my_strlen(name);
	char **env;

	for (env = envp; *env != 0; env++)
	{
		if (my_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&(*env)[len + 1]);
		}
	}
	return (NULL);
}

#include "shell.h"

/**
 * handle_env - handle the env built-in command
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 */
int handle_env(sh_t *data)
{
	int i;

	/* Check if the command is "env" */
	if (_strcmp(data->args[0], "env") == 0)
	{
		/* Print all the environment variables */
		for (i = 0; environ[i] != NULL; i++)
		{
			PRINT(environ[i]);
			PRINT("\n");
		}
		return (SUCCESS);
	}
	return (FAIL);
}

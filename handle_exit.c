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

#include "shell.h"
#include <ctype.h>

/**
 * handle_exit - handle the exit built-in command
 * @data: a pointer to the data structure
 *
 * Return: (Success) 0 is returned
 */
int handle_exit(sh_t *data)
{
	int i;
	int status;

	/* Check if there is an exit status provided */
	if (data->args[1] == NULL)
	{
		free_data(data);
		exit(EXIT_SUCCESS);
	}

	/* Check if the provided exit status is a valid integer */
	i = 0;
	while (data->args[1][i])
	{
		if (!isdigit(data->args[1][i++]))
		{
			data->error_msg = _strdup("Illegal number\n");
			return (FAIL);
		}
	}

	/* Convert the exit status to an integer */
	status = _atoi(data->args[1]);
	free_data(data);
	exit(status);
}


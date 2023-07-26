#include "shell.h"

/**
 * get_value - Get the value of the variable
 * @name: The name of the variable
 * @envp: The environment variable
 * @last_exit_status: The last status after the variable has
 * been replaced
 *
 * Return: The value of the variable
 */

char *get_value(char *name, char **envp, int last_exit_status)
{
	char *value;

	if (str_compare(name, "?") == 0)
	{
		value = itoa(last_exit_status);
	}
	else if (str_compare(name, "$") == 0)
	{
		value = itoa(getpid());
	}
	else
	{
		value = my_getenv(name, envp);
		if (value == NULL)
		{
			value = "";
		}
	}

	return (value);
}

/**
 * replace_variable - Replaces a single variable in a command string
 * @cmd: The command string
 * @start: Pointer to the position of the '$' character
 * @last_exit_status: The last exit status value
 * @envp: The environment variable
 *
 * Return: The new command string with the variable replaced
 */

char *replace_variable(char *cmd, char *start,
		char **envp, int last_exit_status)
{
	char *end;
	char *name;
	char *value;
	char *new_cmd;

	end = start + 1;

	while (my_isalnum(*end) || *end == '_')
	{
		end++;
	}

	name = strndup(start + 1, end - start - 1);
	value = get_value(name, envp, last_exit_status);

	new_cmd = malloc(my_strlen(cmd) + my_strlen(name) +
			my_strlen(value) + 1);
	my_strncpy(new_cmd, cmd, start - cmd);
	my_strcpy(new_cmd + (start - cmd), value);
	my_strcpy(new_cmd + (start - cmd) + my_strlen(value), end);

	free(cmd);
	free(name);

	return (new_cmd);
}

/**
 * variable_replacement - Replaces variables in a command string
 * @cmd: The command string
 * @last_exit_status: Exit the status after the replacement
 * @envp: The environment variable
 *
 * Return: The command string with variables replaced
 */

char *variable_replacement(char *cmd,
		char **envp, int last_exit_status)
{
	char *start = cmd;
	char *new_cmd;

	while ((start = my_strchr(start, '$')) != NULL)
	{
		new_cmd = replace_variable(cmd, start, envp,
				last_exit_status);
		cmd = new_cmd;

		start = cmd;
	}
	return (cmd);
}

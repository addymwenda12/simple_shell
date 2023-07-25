#include "shell.h"

/**
 * replace_variable - Replaces a single variable in a command string
 * @cmd: The command string
 * @start: Pointer to the position of the '$' character
 * @last_exit_status: The last exit status value
 *
 * Return: The new command string with the variable replaced
 */

char *replace_variable(char *cmd, char *start,
		int last_exit_status)
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

	if (start == end || *end != '$')
	{
		return (cmd);
	}

	name = strndup(start + 1, end - start - 1);

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
		value = getenv(name);
		if (value == NULL)
		{
			value = "";
		}
	}

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
 *
 * Return: The command string with variables replaced
 */

char *variable_replacement(char *cmd, int last_exit_status)
{
	char *start = cmd;
	char *new_cmd;

	while ((start = my_strchr(start, '$')) != NULL)
	{
		if (*(start + 1) == '?')
		{
			new_cmd = replace_variable(cmd, start, last_exit_status);
			cmd = new_cmd;
			start += 2;
		}
		else if (*(start + 1) == '$')
		{
			new_cmd = replace_variable(cmd, start, getpid());
			cmd = new_cmd;
			start += 2;
		}
		else
		{
			start++;
		}
	}

	return (cmd);
}

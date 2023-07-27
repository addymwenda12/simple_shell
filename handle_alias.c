#include "shell.h"

/**
 * handle_alias - Handles the alias command
 * @cmd_argv: The command arguments
 * @alias_list: Parameter for alias list
 *
 * Return: 0 on success, -1 on error
 */

int handle_alias(char **cmd_argv, alias_t **alias_list)
{
	int i;
	char *name, *value;

	if (cmd_argv[1] == NULL)
	{
		print_all_aliases(alias_list);
	}
	else
	{
		for (i = 1; cmd_argv[i] != NULL; i++)
		{
			name = strtok(cmd_argv[i], "=");
			value = strtok(NULL, "=");

			if (value == NULL)
			{
				print_alias(name, alias_list);
			}
			else
			{
				add_alias(name, value, alias_list);
			}
		}
	}
	return (0);
}

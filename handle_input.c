#include "shell.h"

/**
 * handle_input - Handles the input of shell
 * @commands: The commands to be used
 * @cmd_argv: Array that stores commands
 * @envp: Array that stores environment variable
 * @alias_list: Lists of alias
 */

void handle_input(char **commands, char *cmd_argv[],
		char *envp[], alias_t **alias_list)
{
	int j;

	for (j = 0; commands[j] != NULL; j++)
	{
		handle_command(commands[j], cmd_argv, envp, alias_list);
	}
}

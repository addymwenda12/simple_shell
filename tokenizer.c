#include "shell.h"

/**
 * tokenize - Use to tokenize array of strings
 * @cmd: Command string to be used
 * @cmd_argv: Array of string to be tokenized
 *
 * Return: The tokenized string
 */

void tokenize(char *cmd, char *cmd_argv[])
{
	char *token;
	int i = 0;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		cmd_argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	cmd_argv[i] = NULL;
}

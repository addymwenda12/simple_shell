#include "shell.h"

/**
 * command_separator - Use to separate commands by ;, &&, ||
 * @cmd: Command string to be used
 *
 * Return: The separated commands
 */

char **command_separator(char *cmd)
{
	char **commands = malloc(1024 * sizeof(char *));
	char *command;
	int i = 0;

	if (commands == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	command = strtok(cmd, ";&&||");

	while (command != NULL)
	{
		commands[i] = command;
		i++;
		command = strtok(NULL, ";&&||");
	}
	commands[i] = NULL;

	return (commands);
}

#include "shell.h"

/**
 * tokenize_path - Use to tokenize array of strings
 * @PATH: The path string to be tokenized
 *
 * Return: The tokenized string
 */

char **tokenize_path(char *PATH)
{
	char **tokens = malloc(1024 * sizeof(char *));
	char *token;
	int i = 0;

	if (tokens == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(PATH, ":");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	tokens[i] = NULL;

	return (tokens);
}

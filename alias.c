#include "shell.h"


/**
 * add_alias - Adds an alias to the alias list
 * @name: The name of the alias
 * @value: The value of the alias
 * @alias_list: Parameter for the alias list
 *
 * Return: 0 on success, -1 on error
 */

int add_alias(char *name, char *value, alias_t **alias_list)
{
	alias_t *new_alias = malloc(sizeof(alias_t));

	if (new_alias == NULL)
	{
		perror("Failed to allocate memory");
		return (-1);
	}

	new_alias->name = my_strdup(name);
	new_alias->value = my_strdup(value);
	new_alias->next = *alias_list;
	*alias_list = new_alias;

	return (0);
}

/**
 * print_alias - Prints an alias
 * @name: The name of the alias
 * @alias_list: Parameter for the alias list
 *
 * Return: 0 on success, -1 on error
 */

int print_alias(char *name, alias_t **alias_list)
{
	char *not_found_message = "alias: not found\n";

	alias_t *current = *alias_list;

	while (current != NULL)
	{
		if (str_compare(current->name, name) == 0)
		{
			write(STDOUT_FILENO, current->name, my_strlen(current->name));
			write(STDOUT_FILENO, "='", 2);
			write(STDOUT_FILENO, current->value, my_strlen(current->value));
			write(STDOUT_FILENO, "'\n", 2);
			return (0);
		}
		current = current->next;
	}
	write(STDOUT_FILENO, not_found_message, my_strlen(not_found_message));
	return (-1);
}

/**
 * print_all_aliases - Prints all aliases
 * @alias_list: Parameter for the alias list
 *
 * Return: 0 on success, -1 on error
 */

int print_all_aliases(alias_t **alias_list)
{
	alias_t *current = *alias_list;

	while (current != NULL)
	{
		write(STDOUT_FILENO, current->name, my_strlen(current->name));
		write(STDOUT_FILENO, "='", 2);
		write(STDOUT_FILENO, current->value, my_strlen(current->value));
		write(STDOUT_FILENO, "'\n", 2);

		current = current->next;
	}

	return (0);
}

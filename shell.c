#include "shell.h"

/**
 * handle_exit - Handles the exit function
 * @cmd: The command exit
 * @cmd_argv: The argument vector for the command
 *
 * Return: exit function
 */

void handle_exit(char *cmd, char *cmd_argv[])
{
	int status = 0;

	if (cmd_argv[1] != NULL)
	{
		status = str_to_int(cmd_argv[1]);
	}
	free(cmd);
	exit(status);
}

/**
 * handle_command - Handles command found in the shell
 * @cmd: Command to be used
 * @cmd_argv: Command argument vector array
 * @envp: Environment variable array
 * @alias_list: Lists all aliases in shell
 *
 */

void handle_command(char *cmd, char *cmd_argv[], char *envp[],
		alias_t **alias_list)
{
	tokenize(cmd, cmd_argv);

	if (str_compare(cmd_argv[0], "exit") == 0)
	{
		handle_exit(cmd, cmd_argv);
	}
	else if (str_compare(cmd_argv[0], "setenv") == 0)
	{
		handle_setenv(cmd_argv);
	}
	else if (str_compare(cmd_argv[0], "unsetenv") == 0)
	{
		handle_unsetenv(cmd_argv);
	}
	else if (str_compare(cmd_argv[0], "cd") == 0)
	{
		handle_cd(cmd_argv);
	}
	else if (str_compare(cmd_argv[0], "alias") == 0)
	{
		handle_alias(cmd_argv, alias_list);
	}
	else
	{
		execute_commands(cmd_argv, envp);
	}
}
/**
 * main - Entry point of the program
 * @argc: The argument count for the program
 * @argv: The argument vector for the shell
 * @envp: The evironment variable
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	int j;
	char **commands;
	char *cmd = NULL;
	char *cmd_argv[64];
	size_t len = 0;
	ssize_t read;
	bool from_pipe = false;

	pid_t pid;
	alias_t *alias_list = NULL;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			from_pipe = true;
		}
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = getline(&cmd, &len, stdin);

		if (read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (cmd[strlen(cmd) - 1] == '\n')
		{
			cmd[strlen(cmd) - 1] = '\0';
		}

		commands = command_separator(cmd);
		cmd = variable_replacement(cmd);

		for (j = 0; commands[j] != NULL; j++)
		{
			handle_command(commands[j], cmd_argv, envp, &alias_list);
		}
		free(commands);
	}
	free(cmd);
	return (0);
}

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

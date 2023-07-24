#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_CMD_LEN 128
#define HISTORY_COUNT 20



/* Alias struct */

/**
 * struct alias - alias built in command
 * @name: name of the alias
 * @value: value of the alias
 * @next: Points to the next node
 */
typedef struct alias
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

int print_alias(char *name, alias_t **alias_list);
int print_all_aliases(alias_t **alias_list);
int add_alias(char *name, char *value, alias_t **alias_list);
int handle_alias(char **cmd_argv, alias_t **alias_list);

extern char **environ;

/* Function prototypes for shell */
int my_strlen(char *s);
char *my_strchr(char *s, int c);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, size_t n);
int my_isalnum(int c);
char *variable_replacement(char *cmd);
char *my_strdup(char *src);
char *my_strcat(char *s1, char *s2);
int main(int argc, char *argv[], char *envp[]);
void tokenize(char *cmd, char *cmd_argv[]);
char **tokenize_path(char *PATH);
char *search_path(char *cmd, char **envp);
int str_compare(char *s1, char *s2);
int str_to_int(char *s);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _cd(char *path);
void handle_command(char *cmd, char *cmd_argv[], char *envp[], alias_t **alias_list);
void execute_commands(char *cmd_argv[], char *envp[]);
void handle_cd(char *cmd_argv[]);
void handle_unsetenv(char *cmd_argv[]);
void handle_setenv(char *cmd_argv[]);
void handle_exit(char *cmd, char *cmd_argv[]);
char **command_separator(char *cmd);
char *itoa(int num);

#endif

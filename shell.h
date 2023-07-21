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

/* Function prototypes for shell */
int my_strlen(char *s);
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
char **command_separator(char *cmd);

#endif

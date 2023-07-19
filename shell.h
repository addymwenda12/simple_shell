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

/* Function prototypes for shell */
int main(int argc, char *argv[], char *envp[]);
void tokenize(char *cmd, char *cmd_argv[]);
char **tokenize_path(char *PATH);
char *search_path(char *cmd, char **envp);
int str_compare(char *s1, char *s2);
int str_to_int(char *s);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _cd(char *path);

#endif

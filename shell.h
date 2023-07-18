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
int main(int argc, char *argv[], char *envp[], char *PATH);
char **tokenize_path(char *PATH);
char *search_path(char *cmd, char **envp);

#endif

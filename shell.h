#ifndef SHELL.H
#define SHELL.H

#include <stdio.h>
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

#endif

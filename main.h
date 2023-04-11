#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

char **split_line(char *str, int *count);
void _cd(char **args);
void _exec(char **args);
int num_builtins(void);
void _help(char **args);
void sig_stop(int sNum);

#endif

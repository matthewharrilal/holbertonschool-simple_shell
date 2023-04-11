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

/**
 * struct builtin - associates a command name with a handler function
 * @name: function name
 * @func: fucntion handler
 */

struct builtin {
    char *name;
    void (*func)(char **args);
};

/**
 * builtin builtins - array of built in commands. 
 */

struct builtin builtins[] = {
    {"help", sssh_help},
    {"exit", sssh_exit},
    {"cd", sssh_cd},
};

void _cd(char **args);
void _exit(char **args);
void _exec(char **args);
int num_builtins();
void _help(char **args);
char** split_line(char *line);

#endif
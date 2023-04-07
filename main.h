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

struct builtin {
    char *name;
    void (*func)(char **args);
};

struct builtin builtins[] = {
    {"help", sssh_help},
    {"exit", sssh_exit},
    {"cd", sssh_cd}
};

int sssh_num_builtins()
{
    return sizeof(builtins) / sizeof(struct builtin);
}

void sssh_help(char **args);
char *sssh_read_line();
char** sssh_split_line(char *line);
void sssh_exec(**args);



#endif
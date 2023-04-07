#include "main.h"

/**
 * sssh_help - print a list of available builtins
 * @args: list of builtins
 * Return: always 0 (success)
 */

 void sssh_help(char **args)
 {
    char *helptext =
        "sssh - The Super Simple Shell. "
        "The following commands are available:\n"
        " cd    Change the working directory.\n"
        " exit  Exit the shell.\n"
        " help  Print this help text.\n"
    printf("%s", helptext);
 }
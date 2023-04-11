#include "main.h"

/**
 * _help - print a list of available builtins
 * @args: list of builtins
 * Return: always 0 (success)
 */

void _help(char **args)
{
    char *helptext =
        "sssh - The Super Simple Shell. "
        "The following commands are available:\n"
        " cd    Change the working directory.\n"
        " exit  Exit the shell.\n"
        " help  Print this help text.\n"
    printf("%s", helptext);
}

/**
 * _cd - change the current directory
 * @args: list of arguments
 * Return: always 0 (success)
 */

int _cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "sssh: cd: missingi argument\n");
    }
    else
    {
        if (chdir(args[1])!= 0)
        {
            perror("sssh: cd");
        }
    }
}

/**
 * _exit - exit the shell
 * @args: list of arguments
 * Return: always 0 (success)
 */

void _exit(char **args)
{
    exit(0);
}

/**
 * _num_builtins - 
 * Return: number of registered commands
 */

int num_builtins()
{
	return sizeof(builtins) / sizeof(struct bultin);
}

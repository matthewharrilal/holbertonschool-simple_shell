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

/**
 * sssh_cd - change the current directory
 * @args: list of arguments
 * Return: always 0 (success)
 */

int sssh_cd(char **args)
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
 * sssh_exit - exit the shell
 * @args: list of arguments
 * Return: always 0 (success)
 */

void sssh_exit(char **args)
{
    exit(0);
}

/**
 * sssh_num_builtins - 
 * Return: number of registered commands
 */

int sssh_num_builtins()
{
	return sizeof(builtins) / sizeof(struct bultin);
}

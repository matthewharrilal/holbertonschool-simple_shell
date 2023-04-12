#include "main.h"

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
 * num_builtins - returns the number of builtins
 * Return: number of registered commands
 */

int num_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct bultin));
}

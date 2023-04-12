#include "main.h"

/**
 * _exec - execute a shell command
 * @args: command line arguments
 * Return: always 0 (success)
 */

void _exec(char **args)
{
	for (int i = 0; i < sssh_num_builtins; i++)
	{
		if (strcmp(args[0], sssh_builtins[i].name) == 0)
		{
			sssh_builtins[i].func(args);
			return;
		}
	}
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execve(args[0], args);
		perror("sssh");
		exit(1);
	}
	else if (child_pid < 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("sssh");
	}
}

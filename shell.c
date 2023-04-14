#include "shell.h"
char *tokens[20];

/**
 * main - entry point
 * Return: always 0 (success)
 */

int main(void)
{
	char *line = NULL;
	size_t size = 0;
	char *delims = " \t\n";
	
	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&line, &size, stdin) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		tokenize_path_the_sequel(line, delims, tokens);
		if (!tokens[0])
			continue;
		if (_strcmp(tokens[0], "env") == 0)   
            continue;
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (access(tokens[0], X_OK) == 0)
		{
			make_a_baby(tokens[0], tokens);
		}
		else
		{
			path_finder(tokens);
		}
	}
	return (0);
}

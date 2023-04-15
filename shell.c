#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 on success
 */

int main(void)
{
	char *line = NULL;
	char *tokens[20];
	size_t size = 0;
	char *delims = " \t\n";
	int ret_val = 0;

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
			ret_val = path_finder(tokens);
		}
	}
	return (ret_val);
}

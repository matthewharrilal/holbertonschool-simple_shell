#include "main.h"

/**
 * main - entry point
 * Return: always 0 (success)
 */

int main()
{
	char *line = NULL;
	char **tokens = NULL;

	while (true)
	{
		printf("> ");
		char *line = read_line();
		char **tokens = read_line();

		if (tokens[0] != NULL)
		{
			sssh_exec(tokens);
		}
		free(tokens);
		free(line);
	}
}

/**
 * read_line - read a line from stdin
 * Return: line read from stdin
 */

 int read_line()
 {
	char command[100];

	printf("$ ");
	fgets(command, sizeof(command), stdin);
	printf("%s", command);

	return (0);
 }
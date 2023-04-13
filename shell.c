#include "shell.h"

/**
 * main - entry point
 * Return: always 0 (success)
 */

int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	size_t size = 0;
	int count, CoP = 777;
	char *path = NULL;
	char *paths[20];

	path = getenv("PATH");
	tokenize_path(path, paths);

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&line, &size, stdin) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[0] == '\n')
			continue;
		else
			tokens = split_line(line, &count);
		if (strcmp(tokens[0], "/bin/exit") == 0)
		{
			free(line);
			free(tokens);
			exit(EXIT_SUCCESS);
		}
		if (access(tokens[0], X_OK) == 0)
		{
			CoP = fork();
			if (CoP == 0)
			{
				if (execve(tokens[0], tokens, NULL) == -1)
				{
					perror("Execve Error");
					free(line);
					free(tokens);
					return (-1);
				}
				free(line);
				free(tokens);
				return (0);
			}
				else
					wait(NULL);
		}
			else
				perror("Command Error");
		free(tokens);
	}
}

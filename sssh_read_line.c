#include "main.h"

/**
 * sssh_read_line - read a line from a file
 * Return: string pointer or error message
 */

char *sssh_read_line()
{
	char *line = NULL;
	size_t buflen = 0;
	errno = 0;
	ssize_t strlen = getline(&line, &buflen, stdin);
	if (strlen < 0)
	{
		if (errno)
		{
			perror("sssh");
		}
		exit(1);
	}
	return (line);
}
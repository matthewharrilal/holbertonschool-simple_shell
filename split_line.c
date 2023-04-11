#include "main.h"

/**
 * sssh_split_line - Tokenize a string, splitting on whitespace
 * leading whitespace is ignored. Consecutive whitespaces are
 * treated as a single delimiter.
 * @line: string to tokenize
 * Return: tokenized string
 */

char** sssh_split_line(char *line)
{
	int length = 0;
	int capacity = 16;

	char **tokens = malloc(sizeof(char *) * capacity);
	if (tokens == NULL)
	{
		perror("tokens memory allocation failed");
		exit(1);
	}

	char *delimiter = " \t\r\n";
    char *token = strok(line, delimiter)

	while (token != NULL)
	{
        tokens[length] = token;
        length++;

		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			tokens = malloc(tokens, capacity * sizeof(char*));
			if (tokens == NULL)
			{
				perror("sssh");
                exit(1);
			}
		}
		token = strok(NULL, delimiter);
    }
	
	tokens[length] = NULL;
	return (tokens);
}

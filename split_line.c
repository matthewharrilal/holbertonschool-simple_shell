#include "shell.h"
#define MAX_ARGS 100

/**
 * split_line - splits a string into tokens
 * @str: string to tokenize
 * @count: pointer to an int to store the number of tokens
 * Return: tokenized string
 */

char **split_line(char *str, int *count)
{
	char *token; /* pointer to a token */
	char *words[MAX_ARGS]; /* array of tokens */
	char **result; /* array of tokens to return */
	int i = 0; /* loop counter */
	int j; /* loop counter */
	char *cmd; /* command to execute */

	token = strtok(str, " \n");
	while (token != NULL && i < MAX_ARGS)
	{
		if (i == 0 && token[0] != '/')
		{
			cmd = malloc(strlen("/bin/") + strlen(token) + 1);
			strcpy(cmd, "/bin/");
			strcat(cmd, token);
			words[i] = cmd;
		}
		else
		{
			words[i] = token;
		}
		i++;
		token = strtok(NULL, " \n");
	}
	*count = i;

	result = malloc((i + 1) * sizeof(char *));
	for (j = 0; j < i; j++)
	{
		result[j] = words[j];
	}
	result[i] = NULL;

	return (result);
}

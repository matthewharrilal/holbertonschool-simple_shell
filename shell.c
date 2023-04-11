#include "main.h"

/**
 * main - entry point
 * Return: always 0 (success)
 */

int main()
{
	char *line = NULL; /* line read from stdin, matches char *command */
	char **tokens = NULL; /* array of tokens from line, matches char **words */
	size_t size = 0; /* size of line */
	int count; /* number of words in line */
	int i; /* loop counter */
	int CoP; /* process id */

	while (true)
	{
		printf("Entered while loop: %d\n", CoP);
		printf("-> ");
		getline(&line, &size, stdin); /* read line from stdin */
		printf("Command received: %s", line); /* print line read from stdin */
		tokens = split_string(line, &count); /* split line into words */

		for (i = 0; i < count ; i++) /* print words */
		{
			printf("token %d: %s\n", i, tokens[i]); 
		}

		
		CoP = fork();
		printf("Forked by %d\n", CoP);

		if (CoP == -1)
		{
			perror("Error");
			return (-1);
		}
		else if (CoP == 0)
		{
			printf("Child executing.\n");
			/*system(stringy);*/
			if (execve(words[0], tokens, NULL) == -1)
			/*if (execve(argv[0], argv, NULL) == -1)*/
			{
				perror("Error");
				return (-1);
			}
			return (0);
		}
		else
		{
			printf("Parent waiting.\n");
			wait(NULL);
			printf("Parent awakened.\n"); /*this is how you spell 'awakened'*/
		}
		printf("Just before end of while loop: %d\n", CoP);
	}

	printf("End of prog: %d\n", CoP);
	free(line);
	free(tokens);
	return (0);
}
#define MAX_ARGS 100

char** split_string(char *str, int *count)
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

    result = malloc((i + 1) * sizeof(char*));
    for (j = 0; j < i; j++)
    {
        result[j] = words[j];
    }
    result[i] = NULL;

    return result;
}

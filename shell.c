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
		tokens = split_line(line, &count); /* split line into words */

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
			if (execve(tokens[0], tokens, NULL) == -1)
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
	signal(SIGINT, sig_stop);
	return (0);
}

/**
 * sig_stop - stops signal
 * @sNUM: signal number
 * Returns: void
 */

 void sig_stop(int sNum)
 {
    char *sigMsg = "\nWhat is dead may never die...";

    void(sNUM);
    write(STDOUT_FILENO, sigMsg, _strlen(sigMsg));
    write(STDOUT_FILENO, "\n$ ", 3);
 }
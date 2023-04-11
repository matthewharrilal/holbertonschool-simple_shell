#include "main.h"

/**
 * main - entry point
 * Return: always 0 (success)
 */
void sig_stop(int sNum);

int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	size_t size = 0;
	int count, i, CoP;

	while (true)
	{
		printf("-> ");
		getline(&line, &size, stdin);
		tokens = split_line(line, &count);

		if (strcmp(tokens[0], "/bin/exit") == 0)
			exit(EXIT_SUCCESS);

		if (access(tokens[0], X_OK) == 0)
		{
			CoP = fork();
			if (CoP == 0)
			{
				if (execve(tokens[0], tokens, NULL) == -1)
				{
					perror("Execve Error");
					return (-1);
				}
				return (0);
			}
				else
					wait(NULL);
		}
			else
				perror("Command Error");
		}
	free(line);
	free(tokens);
	signal(SIGINT, sig_stop);
	return (0);
}
/**
 *sig_stop - stoooooopp
 *@sNum: its a number
 *Return: nuthin
 */
void sig_stop(int sNum)
{
	char *sigMsg = "\nYou shell not pass!";

	(void)sNum;
	write(STDOUT_FILENO, sigMsg, strlen(sigMsg));
	write(STDOUT_FILENO, "\n$ ", 3);
}

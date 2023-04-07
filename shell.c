#include "main.h"




/**
 * main - entry point
 * Return: always 0 (success)
 */

int main()
{
	while (true)
	{
		/*display prompt and read in single line*/
		printf("> ");
		char *line = sssh_read_line();
		char **tokens = sssh_read_line();

		if (tokens[0] != NULL)
		{
			sssh_exec(tokens);
		}
		free(tokens);
		free(line);
	}
}
#include "shell.h"

/*
 * make_a_baby - create a child process
 *
 *
*/

int make_a_baby(char *comp_path, char **tokens)
{
    pid_t pid, CoP;
    int status = 0;


    pid = fork();
	if (pid == 0)
	{
	    execve(comp_path, tokens, NULL);
    }
    else if (pid < 0)
    {
        exit(EXIT_FAILURE);
    } 
    else
    {
        do{
            CoP = waitpid(CoP, &status, 0);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }
    return (status);
}

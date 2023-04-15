#include "shell.h"

/**
 * main - Entry point for ghost
 * @argc: arg count
 * @argv: array of input arg strings
 * Return: Always 0. Exit status differs.
 */
int main(int argc, char *argv[])
{
    char *comsave = NULL, *prompt = NULL, *path = NULL, *token = NULL;
    char line[LINE_CAP], *args[40], *paths[40], *pname = argv[0];
    ssize_t nread;
    int i = 0;
    char *comp_path = NULL;

    prompt = "$ ";
    path = getenv("PATH");
    tokenize_path(path, paths);
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, prompt, _strlen(prompt));
        nread = read(STDIN_FILENO, line, LINE_CAP);
        if (nread == -1)
            exit(EXIT_FAILURE);
        else if (nread == 0)
            exit(EXIT_SUCCESS);
        line[nread] = '\0';
        token = tokstr(line, DELIMS, &comsave);
        i = 0;
        while (token != NULL)
        {
            args[i] = token;
            i++;
            token = tokstr(NULL, DELIMS, &comsave);
        }
        args[i] = NULL;
        if (_strcmp(args[0], "exit") == 0)
            exit(EXIT_SUCCESS);
        else if (_strcmp(args[0], "env") == 0)
            continue;
        if (access(args[0], X_OK) == 0)
            make_a_baby(args[0], args);
        else
        {
            i = 0;
            while (paths[i] != NULL)
            {
                comp_path = malloc(_strlen(args[0]) + _strlen(paths[i]) + 2);
                _strcpy(comp_path, paths[i]);
                _strcat(comp_path, "/");
                _strcat(comp_path, args[0]);
                if (access(comp_path, X_OK) == 0)
                {
                    make_a_baby(comp_path, args);
                    break;
                }
                free(comp_path);
                i++;
            }
        }
    }
    (void) argc;
    (void) pname;
    return (0);
}

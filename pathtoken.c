#include "shell.h"

/**
 * tokstr - tokenizes string input based on delims
 * @str: string to tokenize
 * @delim: delim(s) to make tokens based on
 * @saveptr: save point in the string
 * Return: token
 */
char *tokstr(char *str, const char *delim, char **saveptr)
{
    char *token;

    if (str == NULL)
    {
        str = *saveptr;
    }
    str += _strspn(str, delim);
    if (*str == '\0')
    {
        return (NULL);
    }
    token = str;
    str = _strpbrk(token, delim);
    if (str == NULL)
    {
        *saveptr = _strchr(token, '\0');
    }
    else
    {
        *str = '\0';
        *saveptr = str + 1;
    }
    return (token);
}
/**
 * _strspn - calculates byte overlap
 * @s: input string
 * @accept: string w/ bytes to be accepted
 * Return: num of target byte matches
 */
unsigned int _strspn(char *s, const char *accept)
{
    unsigned int bCount = 0;
    int i = 0, j = 0;

    while (accept[i])
    {
        j = 0;
        while ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
        {
            if (s[j] == accept[i])
            {
                bCount++;
            }
            j++;
        }
        i++;
    }
    return (bCount);
}

/**
 * *_strchr - points to first instance of c in s
 * @s: input string
 * @c: char to be located
 * Return: point to first instance or NULL if none
 */
char *_strchr(const char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return ((char *) s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *) s);
    }
    return (NULL);
}

/**
 * *_strpbrk - locks first accepted byte
 * @s: input string
 * @accept: string w/ bytes to be accepted
 * Return: point to locked byte, or NULL if no match
 */
char *_strpbrk(char *s, const char *accept)
{
    int i = 0, j = 0, offset = 999;

    while (accept[i])
    {
        j = 0;
        while (s[j])
        {
            if (s[j] == accept[i])
            {
                if (j < offset)
                {
                    offset = j;
                }
            }
            j++;
        }
        i++;
    }
    if (offset == 999)
        return (NULL);
    return (s + offset);
}

/**
 * cleanstr - removes newline chars from user input
 * @line: user input line
 * Return: always 0
 */
int cleanstr(char *line)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] == '\n')
        {
            line[i] = '\0';
        }
        i++;
    }
    return (0);
}
/**
 * *_strcat - meows 2 strings together
 * @dest: where big string goes and other smol string comes
 * @src: smol string input
 * Return: big string
 */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    while (dest[i])
    {
        i++;
    }
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * *_strcpy - function for to copy chararr
 * @src: source of chararr
 * @dest: destination of chararr
 * Return: finaldestination
 */
char *_strcpy(char *dest, char *src)
{
    int a = 0;

    while (*(src + a))
    {
        *(dest + a) = *(src + a);
        a++;
    }
    dest[a] = '\0';
    return (dest);
}

/**
 * _strlen - function to find length of string
 * @s: string input
 * Return: string length
 */
int _strlen(char *s)
{
    int a = 0;

    while (*(s + a) != '\0')
    {
        a++;
    }
    return (a);
}

/**
 * _strncmp - compares strings up to n chars
 * @s1: first string
 * @s2: second string
 * @n: num of chars to compare
 * Return: first dif or 0 if none
 */
int _strncmp(char *s1, char *s2, int n)
{
    int i = 0, dif = 0;

    while (s1[i] && s2[i] && (i < n))
    {
        if (s1[i] == s2[i])
        {
            i++;
            continue;
        }
        else
        {
            dif = s1[i] - s2[i];
            break;
        }
    }
    return (dif);
}

/**
 * _strcmp - compares strings ASCII values
 * @s1: first string
 * @s2: second string
 * Return: first dif
 */
int _strcmp(char *s1, char *s2)
{
    int i = 0, dif = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] == s2[i])
        {
            i++;
            continue;
        }
        else
        {
            dif = s1[i] - s2[i];
            break;
        }
    }
    return (dif);
}
/**
 * tokenize_path - tokenize user's PATH variable
 * @path: supplied PATH variable content
 * @paths: array to put paths tokens
 * Return: void
 */
void tokenize_path(char *path, char **paths)
{
    char *saveptr;
    char *path_token = tokstr(path, ":", &saveptr);
    int i = 0;

    while (path_token != NULL)
    {
        paths[i] = path_token;
        printf("%s\n", paths[i]);
        i++;
        path_token = tokstr(NULL, ":", &saveptr);
    }
    paths[i] = NULL;
}

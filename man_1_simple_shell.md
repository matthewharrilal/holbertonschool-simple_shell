---
title: SIMPLE_SHELL(1)
section: 1
header: User Manual
footer: SIMPLE_SHELL 1.0.0
date: April 7, 2023
---
# NAME
**Simple Shell** - a simple UNIX command interpreter in C for Holberton School

# SYNOPSIS
hsh [OPTIONS] [FILE]

# DESCRIPTION
The program is a simple shell that runs bash commands entered by the user from the input stream. Each command is a sequence of non-blank words separated by a space, where the first word specifies the name of the command to be executed and subsequent words are considered arguments or flags associated with the command.

The shell can read input lines interactively from standard output or non-interactively from a piped file. It is designed to behave like a UNIX shell, but it does not support all bash features and options.

# OPTIONS
This simple shell program will not ______________________, in accordance with the rubric for Holberton School Course PP1300.

    -c, --command=STRING
        Execute the given command STRING and exit.
    -h, --help
        Display a help message and exit.

# FILE
If a file is provided, the simple shell will execute the commands in the file and exit.

# BUILTIN COMMANDS
    The following commands can be called and handled directly in the shell without requiring a child process to be executed. However, if a failure occurs during execution, these commands may return non-zero exit statuses.

    exit:
        Exits the shell. Returns an exit status of 0 on successful execution. If the command invoked cannot execute, it returns an exit status of 126. If the command is not found, it returns an exit status of 127. In case of a failure due to misuse of the shell builtin, it returns an exit status of 2.
        
    env:
        Prints the variables from the current environment.

# RETURN VALUE
A successful execution of _printf will return the number of characters printed. An error will return -1.

# EXAMPLES
    To run a command using myshell:
        $ myshell -c "ls -l | grep *.txt"
    To run a script file using myshell:
        $ myshell script.sh

# AUTHORS
Written by Sarah Markland & Tayler Coon

# BUGS
Submit bug reports online at:  

<https://github.com/F-O-P>  
<https://github.com/sarahmarkland>

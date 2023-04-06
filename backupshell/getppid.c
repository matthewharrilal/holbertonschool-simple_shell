#include "main.h"

/**
 * getppid - returns the process id of the calling process
 * @pid: the pid of the process
 * Return: the process id of the calling process
 */

void getppid(int pid)
{
	pid_t parent_pid = getppid();
    printf("Parent process PID: %d\n", parent_pid);
}
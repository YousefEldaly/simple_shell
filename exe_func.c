#include "simple_shell.h"


/**
 * open_fun - funtion to excute the code
 *
 * @argv: arg
 *
 * Return: 1 (Success)
 *
 */

int open_fun(char **argv)
{
	int status;
	pid_t processid;

	processid = fork();

	if (processid == 0)
	{
		if (execvp(argv[0], argv) == -1)
			return (0);
	}
	else if (processid < 0)
		perror("Error pid");
	else
	{
		do {
			waitpid(processid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

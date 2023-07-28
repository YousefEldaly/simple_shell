#include "simple_shell.h"

/**
 * main - Entry point
 *
 * Return: 0
 */

int main(void)
{
	int mode = 1;
	char **argv, *command, *prompt = "$ ";

	while (mode)
	{
		if (isatty(STDIN_FILENO))
			_print(prompt);

		command = get_line();
		if (strncmp(command, "exit", 4) == 0)
		{
			free(command);
			exit(0);
		}

		command = handle_line(command);
		argv = split_line(command);
		mode = execute_fun(argv);

		free(command);
		free(argv);
		command = NULL;
		argv = NULL;
	}

	if (command != NULL)
		free(command);
	if (argv != NULL)
		free(argv);

	return (0);
}

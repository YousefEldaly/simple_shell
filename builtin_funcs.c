#include "simple_shell.h"

/* Prototypes */

int shell_cd(char **argv);
int shell_help(char **argv);
int shell_exit(char **argv);


/* built-in function names */

char *func_builtin_names[] = { "cd", "help", "exit"};

int (*builtin_functions[]) (char **) = {&shell_cd, &shell_help, &shell_exit};

/**
 * funcs_count - returns the number of functions in the
 *	func_builtin_names array.
 *
 * Return: num
 *
 */

int funcs_count(void)
{
	return (sizeof(func_builtin_names) / sizeof(char *));
}

/**
 * shell_cd - changes working directory to another directory.
 *
 * @argv: array of functions
 *
 * Return: 1 (success),
 * else, error message
 *
 */


int shell_cd(char **argv)
{
	int i;

	if (argv[1] == NULL)
	{
		perror("Expected argument\n");
	}
	else
	{
		i = chdir(argv[1]);
		if (i != 0)
			perror("Error couldn't change file");
	}
	return (1);
}


/**
 * shell_help - prints shell info
 *
 * @argv: array of functions
 * Return: 1
 *
 */

int shell_help(char **argv)
{
	int i = 0;

	(void)argv;

	printf("Shell Emulator\n");
	printf("Following are built in\n");

	while (i < funcs_count())
	{
		printf(" %s\n", func_builtin_names[i]);
		i++;
	}

	return (1);
}

/**
 * shell_exit - exits the shell
 *
 * @argv: array of functions
 *
 * Return: 1 (Success)
 */

int shell_exit(char **argv)
{
	(void)argv;
	exit(0);
	return (1);
}



/**
 * execute_fun - executes built in funcs or run other funcs
 *
 * @argv: array of parameters
 *
 * Return: 1 (Success)
 *
 */

int execute_fun(char **argv)
{
	int i = 0;

	if (argv[0] == NULL)
		return (1);
	while (i < funcs_count())
	{
		if (strcmp(argv[0], func_builtin_names[i]) == 0)
		{
			return (builtin_functions[i](argv));
		}
		i++;
	}

	return (open_fun(argv));
}

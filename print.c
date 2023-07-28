#include "simple_shell.h"


/**
 * _putchar - prints char (emulates builtin putchar)
 * @c: char to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - prints a string
 * @string: string to print
 *
 * Return: void
 */
void _print(char *string)
{
	int i = 0;

	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
}

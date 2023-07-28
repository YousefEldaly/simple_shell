#include "simple_shell.h"

/**
 * rm_double_quotes - removes double quotes form the input
 *
 * @string: input command
 *
 * Return: void
 *
 */

void rm_double_quotes(char *string)
{
	int i = 0, j = 0;
	int length = strlen(string);



	while (i < length)
	{
		if (string[i] != '"')
		{
			string[j++] = string[i];
		}
		i++;
	}

	string[j] = '\0';
}


/**
 * rp_pound_with_null - replaces the pounds with null
 *
 *
 * @string: string input (line)
 *
 * Return: void
 *
 */


void rp_pound_with_null(char *string)
{
	int i = 0;
	int length = strlen(string);

	while (i < length)
	{
		if (string[i] == '#')
		{
			string[i] = '\0';
			break;
		}
		i++;
	}
}


/**
 * handle_line - handels the line to remove quotes and bounds
 *
 * @line: line
 *
 * Return: @line
 *
 */

char *handle_line(char *line)
{
	char *newline;

	newline = line;
	rp_pound_with_null(newline);
	rm_double_quotes(newline);

	return (newline);
}

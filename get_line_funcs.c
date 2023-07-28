#include "simple_shell.h"

/**
 * get_line - gets the line from user;
 *
 * Return: the line typed by the user (Success).
 * else, EXIT
 *
 */

char *get_line(void)
{
	char *chars_ptr = NULL;
	size_t buff_size = 0;
	int input_chars;

	input_chars = getline(&chars_ptr, &buff_size, stdin);

	if (input_chars == -1)
	{
		if (feof(stdin))
		{
			free(chars_ptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(chars_ptr);
			perror("Get line error");
			exit(EXIT_FAILURE);
		}
	}

	return (chars_ptr);

}

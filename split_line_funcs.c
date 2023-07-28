#include "simple_shell.h"

#define BUFFER_SIZE 1024
#define DELIM " \t\r\n\a"

/**
 * split_line - splits and tokenizes the input function
 * @line: string to tokenize
 *
 * Return: array of tokens
 */
char **split_line(char *line)
{
	int buffer_size = BUFFER_SIZE, i = 0;
	char *tok, **toks = malloc(buffer_size * sizeof(char *));

	if (!toks)
	{
		perror("allocation error\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, DELIM);
	while (tok != NULL)
	{
		toks[i] = tok;
		i++;

		tok = strtok(NULL, DELIM);
	}

	toks[i] = '\0';
	return (toks);
}

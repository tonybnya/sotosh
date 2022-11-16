#include "main.h"

/**
 * sotosh_readline - reads commands from stdin
 *
 * Return: nothing.
 */
char *sotosh_readline(void)
{
	char *line;
	size_t bufsize;

	bufsize = 0;
	line = NULL;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

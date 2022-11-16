#include "main.h"
#define SOTOSH_ARG_BUFSIZE 64
#define SOTOSH_ARG_DELIMITER " \t\r\n\a"

/**
 * sotosh_splitline - separates line into program & args
 * @line: pointer to the input line from stdin
 *
 * Return: array of pointers pointing to each arg
 */
char **sotosh_splitline(char *line)
{
	int bufsize;
	int position;
	char **args;
	char *arg;

	bufsize = SOTOSH_ARG_BUFSIZE;
	position = 0;
	args = malloc(bufsize * sizeof(char *));

	if (!args)
	{
		fprintf(stderr, "sotosh: memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(line, SOTOSH_ARG_DELIMITER);
	while (arg != NULL)
	{
		args[position] = arg;
		position++;

		if (position >= bufsize)
		{
			bufsize += SOTOSH_ARG_BUFSIZE;
			args = realloc(args, bufsize * sizeof(char *));
			if (!args)
			{
				fprintf(stderr, "sotosh: memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		arg = strtok(NULL, SOTOSH_ARG_DELIMITER);
	}

	args[position] = NULL;
	return (args);
}

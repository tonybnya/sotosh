#include "main.h"

/**
 * main - sotosh running
 *
 * Return: Always 0 (On Success)
 */
int main(void)
{
	char **args;
	char *line;
	char *prompt;
	int status;

	prompt = "($) ";

	do {
		printf("%s", prompt);
		line = sotosh_readline();
		args = sotosh_splitline(line);
		status = sotosh_execute(args);

		printf("\n");

		free(line);
		free(args);
	} while (status);

	return (0);
}

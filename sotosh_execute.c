#include "main.h"

/**
 * sotosh_execute - executes the shell
 * @args: command line arguments
 *
 * Return: launch the shell
 */
int sotosh_execute(char **args)
{
	int i;

	int (*builtin_func[]) (char **) = {
		&sotosh_cd,
		&sotosh_help,
		&sotosh_exit
	};
	char *builtin_str[] = {
		"cd",
		"help",
		"exit"
	};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < sotosh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (sotosh_launch(args));
}

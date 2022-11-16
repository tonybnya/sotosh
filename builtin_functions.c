#include "main.h"

/**
 * sotosh_num_builtins - count number of builtin functions
 *
 * Return: the number
 */
int sotosh_num_builtins(void)
{
	char *builtin_str[] = {
		"cd",
		"help",
		"exit"
	};

	return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * sotosh_cd - builtin cd (change directory)
 * @args: commands line arguments
 *
 * Return: 1 on success
 */
int sotosh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "sotosh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("sotosh");
		}
	}

	return (1);
}

/**
 * sotosh_help - prints a mini help paragraph for sotosh
 * @args: command line arguments
 *
 * Return: 1 on success
 */
int sotosh_help(__attribute__((unused)) char **args)
{
	int i;
	char *builtin_str[] = {
		"cd",
		"help",
		"exit"
	};

	printf("Soso Oloju & Tony B. NYA Shell (sotosh)\n");
	printf("Type-in command and arguments\n");
	printf("Some builtin functions have been builded:\n");

	for (i = 0; i < sotosh_num_builtins(); i++)
	{
		printf("%d->  %s\n", i + 1, builtin_str[i]);
	}
	printf("man command is our best friend\n");

	return (1);
}

/**
 * sotosh_exit - exit the shell
 * @args: command line arguments
 *
 * Return: 0 on success
 */
int sotosh_exit(__attribute__((unused)) char **args)
{
	return (0);
}

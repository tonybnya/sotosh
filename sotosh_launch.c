#include "main.h"

/**
 * sotosh_launch - launchs the child process
 * @args: command line arguments
 *
 * Return: 1 as signal to the calling function
 * that we should prompt for input again
 */
int sotosh_launch(char **args)
{
	int status;
	pid_t pid, waiting_pid;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("sotosh error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("sotosh error");
	}
	else
	{
		do {
			waiting_pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		printf("%d", waiting_pid);
	}

	return (1);
}

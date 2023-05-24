#include "shell.h"

/**
 * execute - function to execute the path commands using execve
 * @arg - array of strings
 */
void execute(char **arg)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(arg[0], arg, environ) == -1)
		{
			perror("argv[0]");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pid_t child_pid = waitpid(pid, &status, 0);

		if (child_pid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}

}

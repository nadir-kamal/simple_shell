#include "shell.h"

void _feof(ssize_t nread, char *line);
void sig_handler(int sig_num);
void _isatty(void);

int main(void)
{
	char *line = NULL, **arg, *env, *path;
	size_t n = 0;
	ssize_t nread = 0;
	list_path *head;

	signal(SIGINT, sig_handler);

	while (nread != EOF)
	{
		_isatty();
		nread = _getline(&line, &n);
		_feof(nread, line);
		arg = string_parse(line);

		env = _getenv("PATH");
		head = link_path(env);
		path = _which(arg[0], head);

		if (path)
		{
			free(arg[0]);
			arg[0] = path;
			execute(arg);
		}
		else
		{
			execute(arg);
		}

	}
	free(line);
	free_list(head);
	return (0);
}
/**_isatty - checks if the shell is interactive or non
 *
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ");
}

/**
 * _feof - checks if end of file is reached (CTR - d)
 *@ line - getline buffer
 *@ nread - return value of getline
 */
void _feof(ssize_t nread, char *line)
{
	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(line);
		}
		exit(0);
	}
}
/**
 * sig_handler - handels the (CTR - c) signal
 *@sig_num - signal received from signal function
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	_puts("\n($) ");
}

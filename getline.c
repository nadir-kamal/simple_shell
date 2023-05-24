#include "shell.h"

/**
 * _getline - function that takes a string from the user as input
 *@line - string
 *@n - number of chars
 *@stream
 *return : number of chars
 */
ssize_t _getline(char **line, size_t *n)
{
	size_t bufsize = *n, i = 0;
	char c, *buffer = *line;
	ssize_t len;

	if (buffer == NULL)
	{
		bufsize = 1024;
		buffer = malloc(bufsize);
		if (buffer == NULL)
		{
			return (-1);
		}
	}

	while (read(STDIN_FILENO, &c, 1) != EOF)
	{
		buffer[i++] = c;
		if (c == '\n')
		{
			break;
		}
		if (i + 1 >= bufsize)
		{
			bufsize += 1024;
			buffer = _realloc(buffer, bufsize);
			if (buffer == NULL)
			{
				return (-1);
			}
		}
	}
	buffer[i] = '\0';
	*line = buffer;
	*n = bufsize;
	len = i;

	return (len == 0 ? -1 : 1);
}

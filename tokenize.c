#include "shell.h"

/**
 * string_parse - parsing a string
 *@line - string to parse
 *return : pointer to a string
 */
char **string_parse(char *line)
{
	int bufsize = 32, i = 0;
	char **token = malloc(sizeof(char *) * bufsize);

	if (!token)
	{
		free(token);
		return (NULL);
	}
	token[i++] = _strtok(line, " ");
	while (token[i])
	{
		token[i] = _strtok(NULL, " ");
		if (i >= bufsize)
		{
			bufsize += bufsize;
			_realloc(token, bufsize);
		}
		i++;
	}
	return (token);
}
/**
 * _strtok - tokenize a string
 *@line - pointer to a string
 *@delim - tokenizing delimeter
 *return - string
 */
char *_strtok(char *line, const char *delim)
{
	int i = 0;
	char *start;
	static char *p;

	if (line != NULL)
	{
	p = line;
	}
	start = p;

	if (p == NULL || *p == '\0')
	{
	return (NULL);
	}
	while (p[i] != '\0')
	{
		if (p[i++] == *delim)
		{
		p[i++] = '\0';
		return (start);
		}
		i++;
		}
	return (start);
}
/**
 * _realloc - function to reallocates the memory
 *@ptr - pointer to the reallocated buffer
 *@size - size of the memory to  reallocate
 *return : pointer to the new next block or null on faliure
 */
void *_realloc(void *ptr, size_t size)
{
	 char *new_data, *old;
	 size_t i;

	if (!ptr)
	{
		return (malloc(size));
	}
	else
	{
		old = ptr;
	}
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	new_data = malloc(size);

	if (new_data)
	{
		for (i = 0; i < size; i++)
		{
			new_data[i] = old[i];
		}
		free(ptr);
	}
	else
		return (NULL);

	return (new_data);
}
/**
 * _strcat - function to concate two strings
 *@dest - string
 *@src - string
 *return - pointer to a string
 */
char *_strcat(char *dest, char *src)
{
	int i, len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}

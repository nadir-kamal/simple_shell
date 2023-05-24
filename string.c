#include "shell.h"

/**
 * putchar - prints a single character to the stream
 *@c: a character
 *return : number of chars printed
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _puts - prints a string to the stream
 *@*str: a string
 *return : number of chars printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i++]);
	}
	str[i] = '\0';
	return (i);
}
/**
 * _strlen - gets the string length
 * @s - the string
 * return : the string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - copies a string
 *@str - string
 *return : pointer to a string
 */
char *_strdup(char *str)
{
	int i = _strlen(str);
	char *s = malloc(sizeof(char) * i + 1);

	if (!s)
	{
		return (NULL);
	}

	while (i + 1 >= 0)
	{
		s[i] = str[i];
	}
	return (s);
}

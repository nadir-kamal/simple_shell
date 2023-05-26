#include "shell.h"

/**
 * string_copy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to the destination
 */
char *string_copy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return dest;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;
	return dest;
}

/**
 * string_duplicate - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *string_duplicate(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
		return NULL;

	while (*str++)
		length++;

	result = malloc(sizeof(char) * (length + 1));

	if (!result)
		return NULL;

	for (length++; length--;)
		result[length] = *--str;

	return result;
}

/**
 * print_string - prints a string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void print_string(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * print_string - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buffer[WRITE_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != BUFFER_FLUSH)
		buffer[i++] = c;

	return 1;
}


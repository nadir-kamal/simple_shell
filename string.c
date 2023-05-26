#include <stddef.h>
#include "shell.h"

/**
 * string_length - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int string_length(char *str)
{
	int length = 0;

	if (!str)
		return 0;

	while (*str++)
		length++;
	return length;
}

/**
 * string_compare - performs lexicographic comparison of two strings.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return *str1 - *str2;
		str1++;
		str2++;
	}

	if (*str1 == *str2)
		return (0);
	else
		return *str1 < *str2 ? -1 : 1;
}

/**
 * starts_with - checks if a string starts with another string
 * @str: string to search
 * @prefix: the substring to find
 *
 * Return: address of the next character of str or NULL
 */
char *starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix++ != *str++)
			return (NULL);
	}

	return (char *)str;
}

/**
 * string_concatenate - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *string_concatenate(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return result;
}


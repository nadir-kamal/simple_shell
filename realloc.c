#include "shell.h"

/**
 * custom_memset - Fills memory with a constant byte
 * @s: Pointer to the memory area
 * @b: The byte to fill *s with
 * @n: The number of bytes to be filled
 *
 * Return: Pointer to the memory area s
 */
char *custom_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        s[i] = b;
    }
    return s;
}


/**
 * free_string_array - Frees a string array
 * @strings: String array
 */
void free_string_array(char **strings)
{
    char **temp = strings;

    if (!strings)
        return;

    while (*strings)
    {
        free(*strings);
        strings++;
    }

    free(temp);
}

/**
 * custom_realloc - Reallocates a block of memory
 * @ptr: Pointer to the previous allocated block
 * @old_size: Byte size of the previous block
 * @new_size: Byte size of the new block
 *
 * Return: Pointer to the reallocated block of memory
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;

    if (!ptr)
        return malloc(new_size);

    if (!new_size)
    {
        free(ptr);
        return NULL;
    }

    if (new_size == old_size)
        return ptr;

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;

    old_size = old_size < new_size ? old_size : new_size;

    while (old_size--)
    {
        new_ptr[old_size] = ((char *)ptr)[old_size];
    }

    free(ptr);
    return new_ptr;
}


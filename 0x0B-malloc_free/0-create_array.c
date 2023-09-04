#include "main.h"
#include <stdlib.h>

/**
 * create_array - used to create array
 * @c: character variable containing the value
 * @size: size of bytes
 * Return: array
 */
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	i = 0;
	ptr = malloc(size * sizeof(char));

	if (size == 0 || ptr == 0)
	{
		return (NULL);
	}
	else
	{
		while (i < size)
		{
			i++;
			ptr[i] = c;
		}

	}
	return (ptr);
}

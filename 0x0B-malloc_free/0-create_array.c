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

	if (size == 0)
	{
		return (NULL);
	}
	else
	{
		ptr = malloc(size * sizeof(char));
	}
	if (ptr == 0)
	{
		return (NULL);
	}
	else
	{
		unsigned int i = 0;

		while (i < size)
		{
			i++;
			ptr[i] = c;
		}

	}
	return (ptr);
}

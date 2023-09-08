#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * *_realloc - reallocates a memory block using mallic and free
 * @ptr: pointer to a previous allocated by malloc
 * @new_size: the new size of the new mwmory block
 * @old_size: size of the allocated memory for ptr
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr1 = malloc(new_size);

		if (ptr1 == NULL)
			return (NULL);

		return (ptr1);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	ptr1 = malloc(new_size);

	if (ptr1 == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
		ptr1[i] = ((char *) ptr)[i];
	}

	free(ptr);
	return (ptr1);
}

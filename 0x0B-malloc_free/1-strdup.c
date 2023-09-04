#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a new string, a duplicate of the string str
 * @str: a pointer to a string
 * Return: ptr
 */
char *_strdup(char *str)
{
	char *ptr;
	int i, r = 0;

	if (str == 0)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (r = 0; str[r]; r++)
	{
		ptr[r] = str[r];
	}
	return (ptr);
}

#include "main.h"
#include <stdlib.h>

/**
 * _memset - fills a block of memory with a particular value
 * @s: a pointer address where the value is stored
 * @b: value to be filled
 * @n: number of bytes to be filled
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	for (unsigned int i = 0; i < b; i++)
	{
		s[i] = b;
	}
	return (s);
	n--;
}

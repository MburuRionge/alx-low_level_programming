#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * wildcmp - used to compare strings with wildcards
 * @s1: a variable
 * @s2: a variable
 * Return: 0
 */

int wildcmp(char *s1, char *s2)
{

	if (*s1 == '\0')
	{
		if (*s2 != '\0' && *s2 == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		return (*s2 == '\0');
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}
	return (0);
}

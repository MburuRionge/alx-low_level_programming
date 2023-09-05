#include "main.h"
#include <stdlib.h>

/**
 * str_concat - combines two strings and returns a single combined string
 * @s1: a pointer to a string
 * @s2: a pointer to string
 * Return: concat of s1 and s2
 */

char *str_concat(char *s1, char *s2)
{
	char str;
	int v, m;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	v = m = 0;
	while (s1[v] != '\0')
		v++;
	while (s2[m] != '\0')
		m++;
	str = malloc(sizeof(char) * (v + m + 1));

	if (str == NULL)
		return (NULL);
	v = m = 0;
	while (s1[v] != '\0')
	{
		str[v] = s1[v];
		v++;
	}

	while (s2[m] != '\0')
	{
		str[v] = s2[m];
		v++, m++;
	}
	str[v] = '\0';
	return (str);
}

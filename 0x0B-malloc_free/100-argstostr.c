#include "main.h"
#include <stdlib.h>
/**
 * argstostr - Main argument, entry point
 * @ac: input value
 * @av: pointer variable
 * Return: str
 */

char *argstostr(int ac, char **av)
{
	int i, m, v = 0, p = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (m = 0; av[i][m]; m++)
			p++;
	}
	p += ac;

	str = malloc(sizeof(char) * p + 1);
	if (str == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (m = 0; av[i][m]; m++)
		{
			str[v] = av[i][m];
			v++;
		}
		if (str[v] == '\0')
		{
			str[v++] = '\n';
		}
	}
	return (str);
}

#include "main.h"
#include <stdlib.h>
/**
 * count_word - counts number of words in a string
 * *t: string to evaluate
 * Return: number of words
 */
int count_word(char *t)
{
	int flag, n, p;

	flag = 0;
	p = 0;

	for (n = 0; t[n] != '\0'; n++)
	{
		if (t[n] == ' ')
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			flag = 1;
			p++;
		}
	}

	return (p);
}

/**
 * strtow - splits the input into multiple substrings
 * @str: a string input
 * Return: an array os strings (success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	char **space, *ptr;
	int v, m = 0, len = 0, words, n = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
	{
		return (NULL);
	}

	space = (char **) malloc(sizeof(char *) * (words + 1));
	if (space == NULL)
		return (NULL);

	for (v = 0; v <= len; v++)
	{
		if (str[v] == ' ' || str[v] == '\0')
		{
			if (n)
			{
				end = v;
				ptr = (char *) malloc(sizeof(char) * (n + 1));

				if (ptr == NULL)
					return (NULL);
				while (start < end)
					*ptr++ = str[start++];
				*ptr = '\0';
				space[m] = ptr - n;
				m++;
				n = 0;
			}
		}
		else if (n++ == 0)
			start = v;
	}

	space[m] = NULL;

	return (space);
}

#include "main.h"
#include <stdlib.h>


/**
 * is_palindrome - checks whether the string is palindrome
 * @s: a pointer to a string
 * return: (compare_string(s, 0, strlen_recursion(s-1)))
 */

int is_palindrome (char *s)
{
	if (*s == '\0')
	{
		return (1);
	}
	else
	{
		return (check_pal(s, 0, _strlen_recursion(s - 1)));
	}
}
/**
 * _strlen_recursion - the function is used compare two strings
 * @s: pointer to a string
 * Return: (1 + _strlen_recursion(s + 1)
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	else
	{
		return(1 + _strlen_recursion(s + 1));
	}
}
/**
 * check_pal - checks the characters recursively for palindrome
 * @left: variables
 * @right: variables
 * return: 1 if palindrome, 0 if not
 */
int check_pal(char *s, int left, int right)
{
	if (*(s + left) != *(s + right - 1))
	{
		return (0);
	}
	if (left >= right)
	{
		return (1);
	}
	return (check_pal(s, left + 1, right - 1));

}

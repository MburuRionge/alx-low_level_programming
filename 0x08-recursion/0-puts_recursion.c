#include <stdio.h>
#include "main.h"
/**
 * _puts_recursion - prints each character until it reaches the end
 * @s: a character value
 * Return: (*s)
 */
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar (*s);
		_puts_recursion(s + 1);
	}
	if (*s == '\0')
	{
		_putchar ('\n');
	}
}

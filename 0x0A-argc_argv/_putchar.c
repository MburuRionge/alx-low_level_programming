#include "main.h"
#include <stdio.h>

/**
 * _putchar - prints characters
 * @c: a character value
 * Return: write 1, &c, 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

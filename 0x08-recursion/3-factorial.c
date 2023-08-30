#include "main.h"
#include <stdio.h>

/**
 * factorial - returns the factorial of a number
 * @n: the given value number
 *
 * Return: 1, -1
 */

int factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}

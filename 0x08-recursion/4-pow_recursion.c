#include "main.h"
#include <stdlib.h>

/**
 * _pow_recursion - returns the value of a number raised to the power
 * @x: value of a number
 * @y: a given value
 * Return: (x, y - 1)
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	else if (y < 0)
	{
		return (-1);
	}
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}

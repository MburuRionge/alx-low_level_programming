#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the value of the given number
 * Return: (n, 0)
 */

int _sqrt_recursion(int n)
{
	return (sqrt_a(n, 0));
}
/**
 * sqrt_a - returns  the natural square root of a number
 * @a: value of a number
 * @b: value of a number
 * Return: sqrt(a, b + 1)
 */

int sqrt_a(int a, int b)
{
	if (b * b == a)
	{
		return (b);
	}
	else if (b * b > a)
	{
		return (-1);
	}
	else
	{
		return (sqrt_a(a, b + 1));
	}
}

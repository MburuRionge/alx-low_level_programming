#include <stdlib.h>
#include "main.h"

/**
 * is_prime_number - a afunctions that checks prime numbers
 * prime_a: identifies a prime number
 * @n: given value number
 * @a: a value
 * @b: a value to be measured
 * Return: (a, b + 1)
 */

int prime_a(int a, int b)
{
	if (a <= 1 || (a != b && a % b == 0))
	{
		return (0);
	}
	else if (a == b)
	{
		return (1);
	}
	else
	{
		return (prime_a(a, b + 1));
	}
}
int is_prime_number(int n)
{
	return (prime_a(n, 2));
}

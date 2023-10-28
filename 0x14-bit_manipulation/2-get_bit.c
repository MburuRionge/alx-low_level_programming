#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in adecimal number
 * @index: index of the bit
 * @n: number to search
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 63)
		return (-1);

	value = (n >> index) & 1;

	return (value);
}

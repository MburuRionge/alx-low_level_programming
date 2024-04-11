#include "search_algos.h"
/**
 * linear_search - searches for a value in an array of integers
 * @size: number of elements in array
 * @array: pointer to the first element of the array to search in
 * @value: value to search for
 * Return: first index where value is located
 * Description: prints a value every time it is compared in the array.
 */

int linear_search(int *array, size_t size, int value)
{
	unsigned int i = 0;

	if (array == NULL | size == 0)

	while (i < size)
	{

		printf("Value checked array[%d] = [%d\n]", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

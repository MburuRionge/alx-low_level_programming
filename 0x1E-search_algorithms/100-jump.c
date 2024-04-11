#include "search_algos.h"
/**
 * jump_search - implementation of the jump search algorithm
 * @array: the array to search
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: Returns the index where value is located or -1 on failure
 */
int jump_search(int *array, size_t size, int value)
{
	unsigned int jump, prev;

	if (array == NULL || size == 0)
		return (-1);

	jump = 0;
	prev = 0;
	while (array[jump] < value)
	{
		printf("Value checked array[%d]\n", jump);
		prev = jump;
		jump += sqrt(size);
		if (prev >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", prev, jump);
	while (prev < size)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}
	return (-1);
}

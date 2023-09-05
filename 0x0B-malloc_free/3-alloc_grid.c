#include "main.h"
#include <stdio.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: input value of height
 * Return: pointer to 2 dimensional array
 */

int **alloc_grid(int width, int height)
{
	int **ptr;
	int m, n;

	if (width <= 0 || height <= 0)
		return (NULL);
	ptr = malloc(sizeof(int *) * height);

	if (ptr == NULL)
		return (NULL);

	for (m = 0; m < height; m++)
	{
		str[m] = malloc(sizeof(int) * width);

		if (str[m] == NULL)
		{
			for (; m >= 0; m--)
			{
				free(str[m]);
			}
			free(str);
			return (NULL);
		}
	}

	for (m = 0; m < height; m++)
	{
		for (n = 0; n < width; n++)
			str[m][n] = 0;
	}

	return (str)
}

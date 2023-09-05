#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - main entry point, nested loop to make grid
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
		ptr[m] = malloc(sizeof(int) * width);

		if (ptr[m] == NULL)
		{
			for (; m >= 0; m--)
			{
				free(ptr[m]);
			}
			free(ptr);
			return (NULL);
		}
	}

	for (m = 0; m < height; m++)
	{
		for (n = 0; n < width; n++)
			ptr[m][n] = 0;
	}

	return (ptr);
}

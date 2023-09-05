#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees memory of 2dimension array
 * @grid: 2dimension grid
 * @height: heirht dimension of grid
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

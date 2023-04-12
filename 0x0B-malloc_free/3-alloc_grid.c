#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * alloc_grid - return a pointer to a 2 dimensional array of string
 * @width: width to the grid
 * @height: height ot the grid
 * Return: on success,  returns a pointer to the newly allocated grid.
 * on failure, returns NULL
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
	return (grid);
}

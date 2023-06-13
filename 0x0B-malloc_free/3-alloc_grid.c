#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width : width of the array
 * @height : height of the array
 * Return: NULL if failure or if width or height is negative of 0
 */

int **alloc_grid(int width, int height)
{
	int **d;
	int wi, he;

	if (width <= 0 || height <= 0)
		return (NULL);

	d = malloc(sizeof(int *) * height);

	if (d == NULL)
		return (NULL);

	for (he = 0; he < height; he++)
	{
		d[he] = malloc(sizeof(int) * width);

		if (d[he] == NULL)
		{
			for (; he >= 0; he--)
			{
				free(d[he]);
			}
			free(d);
			return (NULL);
		}
	}
	for (he = 0; he < height; he++)
	{
		for (wi = 0; wi < width; wi++)
			d[he][wi] = 0;
	}
	return (d);
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: the minimum value (inclusive)
 * @max: the maximum value (inclusive)
 *
 * Return: pointer to the newly created array, or NULL on failure or if min > max
 */
int *array_range(int min, int max)
{
    int *arr = NULL;
    unsigned int size, i;

    if (min > max)
    {
        return NULL;
    }

    size = (unsigned int)(max - min + 1); /* Calculate size of the array */

    arr = (int *)malloc(size * sizeof(int)); /* Allocate memory for the array */

    if (arr == NULL)
    {
        return NULL; /* Return NULL if malloc fails */
    }

    for (i = 0; i < size; i++)
    {
        arr[i] = min + i; /* Populate the array with values from min to max */
    }

    return arr;
}

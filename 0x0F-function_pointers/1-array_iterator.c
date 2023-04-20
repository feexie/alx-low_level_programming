#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - function to iterate through arrays
 * @array: pointer to array of int type
 * @size: type pf size_t typedef
 * @action: pointer to function
 * Return: success
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (action == NULL)
		return;
	if (size <= 0)
		return;
	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

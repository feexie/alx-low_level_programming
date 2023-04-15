#include <stdlib.h>
#include "main.h"

/*
 * malloc_checked - Allocation memory using malloc
 * @b: The number of bytes to allocate 
 *
 * Return: A pointer to the allocated memory 
 * 	if malloc fails, the function causes normal process termination
 * 	with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}

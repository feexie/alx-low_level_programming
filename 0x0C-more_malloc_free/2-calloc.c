#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size
 * Return: pointer to the allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int n;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem = malloc(nmemb * size);

	if (mem == NULL)
		return (NULL);

	for (n = 0; n < (nmemb * size); n++)
		mem[n] = 0;
	return (mem);
}

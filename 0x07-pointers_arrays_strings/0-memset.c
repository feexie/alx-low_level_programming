#include "main.h"
/**
 * _memset - fill memory with  constant byte
 * @s: Pointer to the memory area is to be filled.
 * @b: use the constant byte to fill the memory area with.
 * @n: the number of bytes to fill with the constant byte
 * Return: a pointer to the memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}

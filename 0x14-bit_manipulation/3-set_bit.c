#include "main.h"
/**
 * set_bit - set the value of a bit at a given index to i.
 * @n: a pointer to the number to modify
 * @index: the index of the bit to set to 1.
 * Return: 1 if it worked, or -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n |= (1 << index);
	return (1);
}

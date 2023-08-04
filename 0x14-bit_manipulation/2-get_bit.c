#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n : number to convert in binary
 * @index: index of n to return
 * Return: -1 if it failed else the value of the bit at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index > sizeof(unsigned long int) * 8)
		return (-1);

	bit = ((n >> index) & 1);

	return (bit);
}

#include "main.h"
/**
 * get_bit - get bit at index
 * @n: integer number
 * @index: index within binary number
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	bit = n >> index;
	return ((int)(bit & 1));
}

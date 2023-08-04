#include "main.h"

/**
 * binary_to_uint - converts binary to an unsigned int
 * @b: binary number to convert
 * Return: the converted number or 0 if b is null or there is a char
 */

unsigned int binary_to_uint(const char *b)
{
	int mult = 1, len = 0, num = 0;

	if (b == NULL)
		return (0);

	while (b[len])
		len++;

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		num += ((b[len] - '0') * mult);
		mult *= 2;
	}

	return (num);
}

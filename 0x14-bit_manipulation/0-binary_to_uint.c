#include "main.h"
/**
 * binary_to_uint - convert binary to unsigned int
 * @b: binary
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int len = 0;
	int i;

	if (b == NULL)
		return (0);
	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		result  = (result << 1) + (b[i] - '0');
	}
	return (result);
}

#include "main.h"

/**
 * _strpbrk - searches a string for any of a set bytes
 * @s: string to search
 * @accept: set of bytes searched
 * Return: pointer to the byte matched else NULL
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}
	return ('\0');
}

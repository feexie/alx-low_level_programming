#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to check
 * @accept: string with the characters which have to match in s
 * Return: number of bytes in the initial segment of s
 * which consist onlu of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, n, on;

	n = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		on = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				n++;
				on = 1;
			}
		}

		if (on == 0)
			return (n);
	}

	return (0);
}

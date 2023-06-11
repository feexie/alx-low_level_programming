#include "main.h"

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminal null byte
 * to the buffer pointed to by dest
 * @dest : pointer to the buffer we copy the string
 * @src : string copied
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}

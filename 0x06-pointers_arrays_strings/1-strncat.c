#include "main.h"
#include <string.h>
/**
 * _strncat - Concatenates two strings, using at most n bytes from src
 * @dest: Pointer to destination input
 * @src: Pointer to source string
 * @n: Maximum number of bytes to copy from src
 * Return: Pointer to destination string
 */
char *_strncat(char *dest, char *src, int n)
{
	char *start = dest;
	int dest_len = 0;

	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	if (n == 0 && *src != '\0')
	{
		*dest = '\0';
	}
	else
	{
		dest[dest_len + n] = '\0';
	}
	return (start);
}

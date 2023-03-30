#include "main.h"
#include <string.h>
/**
 * _strncpy - Copy at most n characters of string src to dest
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Maximum number of characters to copy
 * Return: Pointer to beginning of destiination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest_start = dest;

	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	return (dest_start);
}

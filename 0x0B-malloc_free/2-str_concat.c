#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: on success, returns a pointer to a newly allocated spaces in memory
 * which contains the content of s1, followed by the content of s2, and null
 * terminated. it returns NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int len1, len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	len1 = strlen(s1);
	len2 = strlen(s2);
	concat_str = malloc(len1 + len2 + 1);
	if (concat_str == NULL)
	{
		return (NULL);
	}
	memcpy(concat_str, s1, len1);
	memcpy(concat_str + len1, s2, len2 + 1);
	return (concat_str);
}

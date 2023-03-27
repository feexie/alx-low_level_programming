#include "main.h"
/**
 * _strlen - Return the lenght of a string
 * @s: pointer to the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; ++s)
		++counter;

	return (counter);
}

#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - function to print name
 * @name: name to print
 * @f: pointer to the function`
 * Return: Always successful
 */

void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		return;
	f(name);
}

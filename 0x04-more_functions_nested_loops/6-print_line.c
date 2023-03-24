#include "main.h"
/**
 * print_line - Prints a straight line of '_' characters to the console
 *
 * @n: The number of times to print the '_' character
 *
 * Description: If n is greater than 0, prints n '_' characters to the console
 * followed by a newline character '\n'. If n is 0 or less, prints only
 * a newline
 * character.
 **/
void print_line(int n)
{
	if (n > 0)
	{
		int i;

		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
	}
	_putchar('\n');
}

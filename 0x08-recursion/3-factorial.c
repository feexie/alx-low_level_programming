#include "main.h"
/**
 * factorial - A  function that returns the factorial of a given number.
 * @n: the number to return.
 * Return: factorial of given number
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}

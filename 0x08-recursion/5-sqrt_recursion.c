#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n:number
 * Return: -1 if n does not have a natural square root
 * else return the result
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	else if (n < 0)
		return (-1);
	else if (n == 1)
		return (1);
	else
		return (function_help(n, 1));
}

/**
 * function_help - function for help in the task
 * @n: number to square
 * @i: number for help
 * Return: 0
 */


int function_help(int n, int i)
{
	if ((i * i) == n)
	{
		return (i);
	}
	else if ((i * i) < n)
	{
		return (function_help(n, i + 1));
	}
	else
	{
		return (-1);
	}
}

#include "main.h"

/**
 * is_prime_number - checks if the input integer is a prime number
 * @n: integer to check
 * Return: 1 if it is else 0
 */

int is_prime_number(int n)
{
	return (prime_number(n, 2));
}

/**
 * prime_number - function to help for the task
 * @n : integer
 * @i : incrementation
 * Return: 0
 */

int prime_number(int n, int i)
{
	if ((n % i == 0 && i < n) || n < 0 || n == 1)
		return (0);
	else if (n % i != 0 && i < n)
		return (prime_number(n, i + 1));
	else
		return (1);
}

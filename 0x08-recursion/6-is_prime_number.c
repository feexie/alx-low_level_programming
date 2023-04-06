#include "main.h"
int is_prime_helper(int n, int i);
/**
 * is_prime_number - returns 1 if input integer is prime, 0 otherwise
 * @n: integer input
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	else
	{
		return (is_prime_helper(n, 2));
	}
}
/**
 * is_prime_helper - helper function for is_prime_number
 * @n: integer input
 * @i: divisor to test for primality
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
	if (i == n)
	{
		return (1);
	}
	else if (n % i == 0)
	{
		return (0);
	}
	else
	{
		return (is_prime_helper(n, i + 1));
	}
}

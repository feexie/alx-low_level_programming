#include "main.h"
/**
 * print_binary - convert unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	putchar((n & 1) ? '1' : '0');
}

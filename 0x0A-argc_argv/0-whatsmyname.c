#include <stdio.h>

/**
 * main - prints its name
 * followed by a new line
 * @argc: count of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
#include <stdio.h>

/**
 * main - prints all arguments it receives
 * only print one argument per line, ending with a new line
 * @argc: count of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}

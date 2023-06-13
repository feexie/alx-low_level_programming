#include <stdlib.h>
#include <stdio.h>

/**
 * main - adds positive numbers
 * if one of the number contains a non-digits print error
 * @argc: count of arguments
 * @argv : array of arguments
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int i, j, result;

	result = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		result += atoi(argv[i]);
	}
	printf("%d\n", result);
	return (0);
}

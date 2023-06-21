#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - prints result
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	int numb1, numb2;
	char *operator;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	numb1 = atoi(argv[1]);
	numb2 = atoi(argv[3]);
	operator = argv[2];

	if (get_op_func(operator) == NULL || operator[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*operator == '/' && numb2 == 0) || (*operator == '%' && numb2 == 0))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(operator)(numb1, numb2));
	return (0);
}

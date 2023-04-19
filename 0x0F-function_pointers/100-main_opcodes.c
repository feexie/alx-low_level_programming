#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: program prints opcodes of it own main function
 * @argc: argument counter
 * @argv: vector argument
 * Return: success
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *ptr = (unsigned char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", ptr[i] & 0xFF);
		if (i != num_bytes - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}

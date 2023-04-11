#include <stdio.h>

/**
 * main - Entry point of the program
 * Description: Prints the name of the program (the first command line
 * argument), followed by a new line.
 * @argc: Number of command line arguments
 * @argv: Array of strings containing the command line arguments
 * Return: 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	/* Print the name of the program */
	printf("%s\n", argv[0]);

	/* Return 0 to indicate successful termination */
	return 0;
}

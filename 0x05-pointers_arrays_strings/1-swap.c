#include "main.h"

/**
 * swap_int - function that swaps the values of two integers
 * @a: first pointer to be swapped
 * @b: second pointer to be swapped
 * return 0
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


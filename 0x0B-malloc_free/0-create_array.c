#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates and initializes an array of chars
 * @size: The size of the array to create
 * @c: The character to initialize the array with
 * Return: A pointer to the array, or NULL if size is 0 or if memory allocation fails
 */
char *create_array(unsigned int size, char c)
{
    if (size == 0)
    {
        return NULL;
    }

    char *arr = malloc(sizeof(char) * size);

    if (arr == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = c;
    }

    return arr;
}

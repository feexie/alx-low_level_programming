#include "lists.h"
#include <stddef.h>

/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: pointer to the head of the list
 * Return: the number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t count = 0; // Initialize a count variable to keep track of elements

    while (h != NULL)
    {
        count++; // Increment the count for each element in the list
        h = h->next; // Move to the next element
    }

    return count; // Return the number of elements
}


#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a linked list_t list
 * @h: pointer to the head of the linked list
 *
 * Return: the number of nodes in the linked list
 */

size_t print_list(const list_t *h)
{
    size_t count = 0;

    for (; h != NULL; h = h->next, count++)
    {
        printf("[%d] %s\n", h->len, h->str);
    }

    return count;
}


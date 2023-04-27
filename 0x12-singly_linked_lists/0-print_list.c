#include "lists.h"
#include <stdio.h>

/*
 * Print lists- Print all element of a list_t
 * @lists.h: list to print
 * Return the number of nodes
 */

size_t print_list(const list_t *h)
{
    size_t count = 0;

    do {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%d] %s\n", h->len, h->str);

        h = h->next;
        count++;
    } while (h != NULL);

    return count;
}


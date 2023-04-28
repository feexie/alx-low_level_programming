#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the head of the linked list
 *
 * Return: the number of nodes in the linked list
 */
size_t print_list(const list_t *h)
{
	size_t num_nodes = 0;

	while (h != NULL)
	{
		printf("[%d] %s\n", h->len, h->str == NULL ? "(nil)" : h->str);
		num_nodes++;
		h = h->next;
	}

	return (num_nodes);
}

#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node with a given value at a specific
 * 				position in a doubly linked list.
 *
 *  @h: A pointer to a pointer to the head of the doubly linked list.
 *  @idx: The index at which to insert the new node.
 *
 *  Return: If the function succeeds, returns a pointer to the newly inserted node.
 *  		If the function fails, returns NULL.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current = *h;
	unsigned int i = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = current;
		new_node->prev = NULL;
		if (current != NULL)
			current->prev = new_node;
		*h = new_node;
		return (new_node);
	}


	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}


	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}


	new_node->next = current->next;
	new_node->prev = current;
	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}

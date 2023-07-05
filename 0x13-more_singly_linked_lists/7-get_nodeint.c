#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node a listint_t list
 * @head: pointer to the head
 * @index: index to return
 * Return: the nth node of NULL if the node doesn't exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int rm;

	for (rm = 0; rm < index; rm++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}

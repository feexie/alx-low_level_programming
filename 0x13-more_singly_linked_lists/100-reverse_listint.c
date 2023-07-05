#include "lists.h"

/**
 * reverse_listint - reverse a listint_t linked list
 * @head: pointer to pointer to the head
 * Return: poitner to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *before, *after;

	if (head == NULL || *head == NULL)
		return (NULL);

	before = NULL;

	while ((*head)->next != NULL)
	{
		after = (*head)->next;
		(*head)->next = before;
		before = *head;
		*head = after;
	}

	(*head)->next = before;

	return (*head);
}

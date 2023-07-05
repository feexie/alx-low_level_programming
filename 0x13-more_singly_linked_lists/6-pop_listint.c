#include "lists.h"

/**
 *  pop_listint - delets the head node of a listint_t list
 * @head : pointer to a pointer to the head of the list
 * Return: the head node's data (n) or 0 if the linked list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int data;

	if (*head == NULL)
		return (0);

	tmp = *head;
	data = (*head)->n;
	*head = (*head)->next;
	free(tmp);

	return (data);
}

#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the denf of a listint_t list
 * @head: pointer to the adress of the head of the list
 * @n: elements to add
 * Return: the address of the new elements, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *fin;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	fin = *head;
	while (fin->next != NULL)
		fin = fin->next;
	fin->next = new;
	return (*head);
}

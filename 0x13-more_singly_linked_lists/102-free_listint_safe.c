#include "lists.h"
/**
 * free_listint_safe - frees a linked list of integers (listint_t)
 * @h: pointer to the head of the list
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nnodes = 0;
	listp_t *hptr, *new, *add;
	listint_t *curr;

	hptr = NULL;
	while (*h != NULL)
	{
		new = malloc(sizeof(listp_t));
		if (new == NULL)
			exit(98);
		new->p = (void *)*h;
		new->next = hptr;
		hptr = new;
		add = hptr;
		while (add->next != NULL)
		{
			add = add->next;
			if (*h == add->p)
			{
				*h = NULL;
				free_listp2(&hptr);
				return (nnodes);
			}
		}
		curr = *h;
		*h = (*h)->next;
		free(curr);
		nnodes++;
	}
	*h = NULL;
	free_listp2(&hptr);
	return (nnodes);
}
/**
 * free_listp2 - frees a linked list structure (listp_t)
 * @head: pointer to the head of the list
 * Return: void
 */
void free_listp2(listp_t **head)
{
	listp_t *current;
	listp_t *temp;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node at the end of a list_t
 * @head: pointer to the head of the list
 * @str: string to add
 * Return: the address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	int len = 0;
	list_t *new, *fin;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	if (str == NULL)
	{
		free(new);
		return (NULL);
	}

	while (str[len])
		len++;

	new->str = strdup(str);
	new->len = len;
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

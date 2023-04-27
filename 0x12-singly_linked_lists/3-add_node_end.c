#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - Adds a new node at the end of a list_t.
 * @head: A pointer to the head of the list.
 * @str: The string to add.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
        int len = 0;
        list_t *new_node, *last_node;

        new_node = malloc(sizeof(list_t));
        if (new_node == NULL)
                return (NULL);

        if (str == NULL)
        {
                free(new_node);
                return (NULL);
        }

        while (str[len])
                len++;

        new_node->str = strdup(str);
        if (new_node->str == NULL)
        {
                free(new_node);
                return (NULL);
        }

        new_node->len = len;
        new_node->next = NULL;

        if (*head == NULL)
        {
                *head = new_node;
                return (*head);
        }

        last_node = *head;
        while (last_node->next != NULL)
                last_node = last_node->next;

        last_node->next = new_node;
        return (*head);
}

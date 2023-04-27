#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list_t list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The number of elements in the list_t list.
 */

size_t list_len(const list_t *h)
{ 
    if (h == NULL) 
         return 0; 
  
    return 1 + list_len(h->next); 
}

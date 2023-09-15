#include "lists.h"

int sum_dlistint(dlistint_t *head)
{
    int sum = 0; // Initialize the sum to 0

    // Iterate through the list and accumulate the sum
    while (head != NULL)
    {
        sum += head->n; // Add the current node's data to the sum
        head = head->next; // Move to the next node
    }

    return sum; // Return the sum
}

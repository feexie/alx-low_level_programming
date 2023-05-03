#include "lists.h"
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head node of the list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	if (!head)
		exit(98);
	slow = head;
	fast = head->next;
	while (fast && fast < slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next ? fast->next->next : NULL;
		count++;
	}
	if (fast)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		printf("-> [%p] %d\n", (void *)fast, fast->n);
		count += 2;
		slow = slow->next;
		fast = fast->next ? fast->next->next : NULL;
	}
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		count++;
	}
	return (count);
}

#include "lists.h"

/**
 * print_listint - Print all the elements of listint_t list.
 * @h: The pointer to the head of the linked list.
 *
 * Return: The number of nodes (elements) in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t nodeCount = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		nodeCount++;
		h = h->next;
	}

	return (nodeCount);
}

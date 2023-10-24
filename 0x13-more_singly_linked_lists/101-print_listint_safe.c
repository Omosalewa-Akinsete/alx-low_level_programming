#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Returns: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *loop_node = NULL;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);

		if (current >= loop_node)
		{
			fprintf(stderr, "Linked list is a loop\n");
			exit(98);
		}

		loop_node = current;
		current = current->next;
		count++;
	}

	return (count);
}

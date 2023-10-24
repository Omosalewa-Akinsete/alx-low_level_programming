#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - The function that frees a listint_t list.
 * @head: The pointer to the head of the linked list.
 */
void free_listint(listint_t *head)
{
	listint_t *current, *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

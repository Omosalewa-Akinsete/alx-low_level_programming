#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *current = *head;
	listint_t *temp;
	size_t size = 0;

	while (current != NULL)
	{
		size++;
		temp = current;
		current = current->next;

		temp->next = NULL;
		free(temp);

		if (current == *head)
		{
			*head = NULL;
			break;
		}
	}

	return (size);
}

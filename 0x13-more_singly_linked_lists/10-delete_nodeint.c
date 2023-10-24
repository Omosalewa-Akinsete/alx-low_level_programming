#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index -  Deletes a node at a given index in a listint_t linked list.
 * @head: The pointer to a pointer to the head of the the linked list.
 * @index:The index of the node to delelte.
 *
 * Returns:1 if it successfully deleted, -1 if the node at the given indexdoes not exist.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *dnode;
	unsigned int i = 1;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (1);
	}

	prev = *head;
	for (i = 0; prev && i < index - 1; i++)
		prev = prev->next;

	if (!prev || prev->next)
		return (-1);

	temp = prev->next;
	prev->next = temp->next;
	free(temp);

	return (1);
}


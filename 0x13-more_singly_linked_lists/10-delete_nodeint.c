#include "lists.h"

/**
 * delete_nodeint_at_index -  Deletes a node at a given index in a linked list.
 * @head: A pointer to a pointer to the head of the the linked list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if it succeeds, -1 if it fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *dnode;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (1);
	}

	dnode = *head;
	for (i = 0; dnode && i < index - 1; i++)
		dnode = dnode->next;

	if (!dnode || dnode->next)
		return (-1);

	temp = dnode->next;
	dnode->next = temp->next;
	free(temp);

	return (1);
}

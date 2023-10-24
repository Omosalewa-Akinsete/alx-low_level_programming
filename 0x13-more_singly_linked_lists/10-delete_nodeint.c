#include "lists.h"

/**
 * delete_nodeint_at_index -  Deletes the node at a given index.
 * @head: The pointer to a pointer to the headerof the the linked list.
 * @index:The index of the node to be deleted (starting at 0).
 *
 * Returns:1 if it succeeded, -1 if it fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	while (current != NULL)
	{
		if (i == index - 1)
		{
			if (current->next  == NULL)
				return (-1);
			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (-1);
		}
		current = current->next;
		i++;
	}

	return (-1);
}

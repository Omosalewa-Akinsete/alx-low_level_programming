#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t and returns the data.
 * @head:  A pointer to a pointer to the head of a linked list.
 *
 * Return: The data from the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data = 0;

	if (head != NULL && *head != NULL)
	{
		temp = *head;
		data = temp->n;
		*head = (*head)->next;
		free(temp);
	}

	return (data);
}

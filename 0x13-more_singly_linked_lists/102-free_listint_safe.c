#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - A function that frees a list
 * @h: A pointer listint_t structure
 * Return: The size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	slow = *h;
	fast = *h;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = slow->next;

			while (slow != fast)
			{
				count++;
				slow = slow->next;
			}
			slow = *h;
			while (slow != fast)
			{
				slow = slow->next;
				temp = fast->next;
				free(fast);
			}
			temp = fast->next;
			free(fast);
			fast = temp;
		}
		while (fast->next != slow)
		{
			free(fast);
			*h = NULL;
			return (count);
		}
	}
/**	size_t count = 0;*/

	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		count++;
	}
	*h = NULL;
	return (count);
}

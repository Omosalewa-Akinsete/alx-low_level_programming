#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe -  Frees a listint_t list.
 * @h: The pointer to a pointer to the header of the linker list.
 *
 * Returns: The size of the list that was freed.
 *	If a loop is detected, the function sets the head of the NULL and returns 0.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *temp;
	listint_t *loop_node = NULL;

	current = *h;

	while (current)
	{
		size++;

		if (current >= loop_node)
		{

			*h = NULL;
			break;
		}

		loop_node = current;
		temp = current->next;
		free(current);
		current = temp;
	}

	*h = NULL;
	return (size);
}

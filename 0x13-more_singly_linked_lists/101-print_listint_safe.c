#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the header of a linked list.
 * Return: Always 0.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slower, *faster;
	size_t count = 0;

	slower = head;
	faster = head;

	while (slower && faster && faster->next)
	{
		printf("%d\n", slower->n);
		slower = slower->next;
		faster = faster->next->next;

		if (slower == faster)
		{
			printf("-> [%p] %d\n", (void *)faster, faster->n);
			exit(98);
		}
	}
	if (!faster)
	{
		return (0);
	}

	while (slower != NULL)
	{
		printf("%d\n", slower->n);
		slower = slower->next;
		count++;
	}
	return (count);
}

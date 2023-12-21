#include "hash_tables.h"
#include <stdlib.h>

/**
 * free_node_list - Frees a linked list of hash nodes
 * @node: The head of a linked list
 */
static void free_node_list(hash_node_t *node)
{
	while (node != NULL)
	{
		hash_node_t *temp = node;

		node = node->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	for (unsigned long int i = 0; i < ht->size; ++i)
	{
		free_node_list(ht->array[i]);
	}

	free(ht->array);
	free(ht);
}

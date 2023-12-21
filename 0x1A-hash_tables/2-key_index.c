#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - Gives you the index of a key
 * @key: The key to calculate the index for
 * @size: The sizeof the array of the hash table
 *
 * Return: The index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);

	unsigned long int index = hash_value % size;

	return (index);
}

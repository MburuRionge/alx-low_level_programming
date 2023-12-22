#include "hash_table.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table
 * @key: The key to add cannot be an empty string
 * @value: The value associated with key
 * Return: 0 failure else 1
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *more, *temp;
	char *new;
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || ht->size == 0 || key == NULL
			|| strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new = strdup(value);
			if (new == NULL)
				return (0);
			free(temp->value);
			temp->value = new;
			return (1);
		}
		temp = temp->next;
	}
	more = make_hash_node(key, value);
	if (more == NULL)
		return (0);
	more->next = ht->array[index];
	ht->array[index] = more;
	return (1);
}

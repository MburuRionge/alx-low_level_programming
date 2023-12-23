#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *next, *current;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (ht->array[i] != NULL)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;

	free(ht);
	ht = NULL;
}

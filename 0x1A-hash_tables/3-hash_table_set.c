#include "hash_tables.h"

/**
 * make_hash_node - creates a new hash node
 * @key: key for thw node
 * @value: for the node
 * Return NULL on failure or the new node
 */

hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key ==  NULL)
	{
		free(node);
		return (NULL);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table
 * @key: The key to add cannot be an empty string
 * @value: The value associated with key
 * Return: 0 failure else 1
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_node, *temp;
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

	hash_node = make_hash_node(key, value);
	if (hash_node == NULL)
		return (0);
	if (index >= ht->size)
	{
		free(hash_node->key);
		free(hash_node->value);
		free(hash_node);
		return (0);
	}
	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}

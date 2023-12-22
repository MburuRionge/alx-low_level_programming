#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 * Return: pointer to the new table, or NULL on failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash;
	unsigned long int i;

	shash = malloc(sizeof(shash_table_t));
	if (shash == NULL)
		return (NULL);
	shash->size = size;
	shash->ahead = NULL;
	shash->stail = NULL;
	shash->array == malloc(sizeof(shash_node_t) * size);
	if (shash->array == NULL)
	{
		free(shash);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		shash->array[i] = NULL;
	}
	return (shash);
}

/**
 * make_shash_node - makes a node for the sorted bash table
 * @key: key for the data
 * @value: data to be stored
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *shn;

	shn = malloc(sizeof(shash_node_t));
	if (shn == NULL)
		return (NULL);
	shn->key = strdup(key);
	if (shn->key == NULL)
	{
		free(shn);
		return (NULL);
	}
	shn->value = strdup(value);
	if (shn->key == NULL)
	{
		free(shn->key);
		free(shn);
		return (NULL);
	}
	shn->next = shn->snext = shn->prev = NULL;
	return (shn);
}

/**
 * add_to_sorted_list - Add a node to the sorted (by key's ASCII) linked list
 * @table: the sorted hash table
 * @node: the  node to add
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	temp = table->shead;
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			node->next = temp;
			node->prev = temp->spev;
			temp->sprev = node;
			if (node->spev != NULL)
				node->spev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp = temp->next;
	}
	node->sprev = table->stail;
	table->stail->next = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key for the data
 * @value: data to be stored
 * Return: pointer to the new node, or NULL on failur
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new;
	shash_node_t *shin, *temp;

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
	shin = make_shash_node(key, value);
	if (shin == NULL)
		return (0);
	shin->next = ht->array[index];
	ht->array[index] = shin;
	add_to_sorted_list(ht, shin);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: hash table
 * @key: key to the data
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 || key == NULL
			|| strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("(");
	temp = ht->shead;
	while (temp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
		temp = temp->snext;
	}
	printf(")\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flag = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("(");
	temp = ht->stail;
	while (temp != NULL)
	{
		if (flag == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flag = 1;
		temp = temp->sprev;
	}
	printf(")\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i] != NULL)
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}

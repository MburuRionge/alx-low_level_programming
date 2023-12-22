#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algirithm.
 * @str: The string to hash.
 * Return: The calculated hash
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + c;

	return (hash);
}

#include <stdlib.h>
#include "lists.h"
/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer variable
 * Retuns: number of elements in h
 */
size_t list_len(const list_t *h)
{	
	size_t ph = 0;

	while (h)
	{
		ph++;
		h = h->next;
	}
	return (ph);
}

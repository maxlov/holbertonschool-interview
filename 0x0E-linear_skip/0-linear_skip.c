#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - uses a skip list to find value of list
 *
 * @list: Pointer to the head of the list
 * @value: Value that is being searched for
 *
 * Return: Pointer to the node found or null of failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *end;

	if (list == NULL)
		return (NULL);

	for (current = list; current->express != NULL; current = current->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
					current->express->index, current->express->n);
		if (current->express->n > value)
			break;
	}
	if (current->express == NULL)
		for (end = current; end->next != NULL; end = end->next)
			if (end->next->next == NULL)
				current->express = end->next;
	printf("Value found between indexes [%lu] and [%lu]\n",
					current->index, current->express->index);
	for (; current != NULL; current = current->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
					current->index, current->n);
		if (current->n == value)
			return (current);
	}
	return (NULL);
}

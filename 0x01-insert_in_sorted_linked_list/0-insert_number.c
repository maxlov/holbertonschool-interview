#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts node into sorted list
 * @head: head of list
 * @number: number to insert
 * Return: address of new node or NULL on failure
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *new;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (current == NULL)
	{
		*head = new;
	}
	else if (current->n >= number)
	{
		new->next = current;
		*head = new;
	}
	else
	{
		for (; current->next != NULL; current = current->next)
			if (current->next->n >= number)
			{
				new->next = current->next;
				current->next = new;
				return (new);
			}
		new->next = current->next;
		current->next = new;
	}
	return (new);
}
